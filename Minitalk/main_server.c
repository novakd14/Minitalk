/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:09:17 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/06 13:15:36 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_message		g_mess;

static char	read_size_prop(void)
{
	char	size_prop;

	size_prop = 0;
	if (g_mess.recieved == FALSE)
		pause();
	g_mess.recieved = FALSE;
	while (TRUE)
	{
		if (g_mess.bit == 1)
		{
			size_prop++;
			if (kill_with_check(g_mess.pid, SIGNAL_SENDING) == ERROR)
				return (0);
		}
		else
			return (size_prop + 1);
	}
}

static size_t	init_message(char size_prop, char **message)
{
	size_t	size;
	char	bit_num;

	size = 0;
	bit_num = 0;
	if (kill_with_check(g_mess.pid, SIGNAL_SENDING) == ERROR)
		return (0);
	while (TRUE)
	{
		bit_num++;
		size <<= 1;
		size += g_mess.bit;
		if (bit_num >= size_prop * 8)
			break ;
		else if (kill_with_check(g_mess.pid, SIGNAL_SENDING) == ERROR)
			return (0);
	}
	*message = (char *)ft_calloc(size, sizeof(char));
	if (*message == NULL)
	{
		ft_putstr_fd("ERROR: Could not allocate memory.\n", STDERR_FILENO);
		return (0);
	}
	return (size);
}

static void	read_message(char *message, size_t size)
{
	size_t	bit_num;

	bit_num = 0;
	while (bit_num < (size * 8))
	{
		if (kill_with_check(g_mess.pid, SIGNAL_SENDING) == ERROR)
			return ;
		message[bit_num / 8] <<= 1;
		message[bit_num / 8] += g_mess.bit;
		bit_num++;
	}
	write(STDOUT_FILENO, message, size);
	write(STDOUT_FILENO, "\n", 1);
}

static void	recieve_message(void)
{
	char	size_prop;
	size_t	size;
	char	*message;

	message = NULL;
	size_prop = read_size_prop();
	if (size_prop == 0)
		return ;
	size = init_message(size_prop, &message);
	if (size == 0)
		return ;
	read_message(message, size);
	free(message);
	kill(g_mess.pid, SIGNAL_FINISH);
}

int	main(void)
{
	init_signals();
	ft_printf("%i\n", getpid());
	while (TRUE)
		recieve_message();
	return (EXIT_SUCCESS);
}
