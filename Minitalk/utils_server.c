/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:54 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/06 02:27:38 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

extern t_message	g_mess;

// int	advanced_pause(void)
// {
// 	if (usleep(WAIT_TIME) != -1)
// 		ft_printf("NOTE: Waited for the whole usleep.\n");
// 	if (g_mess.used == TRUE)
// 		return (-1);
// 	g_mess.used = TRUE;
// 	return (0);
// }

t_status	kill_with_check(pid_t pid, int signal)
{
	int	time;

	if (kill(pid, signal) == -1)
	{
		ft_putstr_fd("ERROR: Can not reach client.\n", STDERR_FILENO);
		return (ERROR);
	}
	time = 0;
	while (g_mess.recieved == FALSE)
	{
		if (time > WAIT_TIME)
		{
			ft_putstr_fd("ERROR: Did not recieve confirmation from client.\n",
				STDERR_FILENO);
			return (ERROR);
		}
		time += TIME_STEP;
		usleep(TIME_STEP);
	}
	g_mess.recieved = FALSE;
	return (SUCCESS);
}

static char	read_size_prop(void)
{
	char	size_prop;

	size_prop = 0;
	// while (g_mess.recieved == FALSE)
	// 	continue ;
	if (g_mess.recieved == FALSE)
		pause();
	g_mess.recieved = FALSE;
	ft_printf("NOTE: Entering the first loop.\n"); // TEMP
	while (TRUE)
	{
		if (g_mess.bit == 1)
		{
			size_prop++;
			if (kill_with_check(g_mess.pid, SIGNAL_SENDING) == -1)
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
	if (kill_with_check(g_mess.pid, SIGNAL_SENDING) == -1)
		return (0);
	while (TRUE)
	{
		bit_num++;
		ft_printf("bit num: %i\n", bit_num); // TEMP
		size <<= 1;
		size += g_mess.bit;
		if (bit_num >= size_prop * 8)
			break ;
		else if (kill_with_check(g_mess.pid, SIGNAL_SENDING) == -1)
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

// static void	read_message(char *message, size_t size, int *signal)
// {
// 	size_t	bit_num;

// 	bit_num = 0;
// 	kill_with_check(g_mess.pid, *signal);
// 	*signal = SIGNAL0 + SIGNAL1 - *signal;
// 	while (TRUE)
// 	{
// 		message[bit_num / 8] <<= 1;
// 		message[bit_num / 8] += g_mess.bit;
// 		kill_with_check(g_mess.pid, *signal);
// 		*signal = SIGNAL0 + SIGNAL1 - *signal;
// 		bit_num++;
// 		if (bit_num == size * 8)
// 			break ;
// 	}
// 	write(STDOUT_FILENO, message, size);
// 	write(STDOUT_FILENO, "\n", 1);
// }

void	recieve_message(void)
{
	char	size_prop;
	size_t	size;
	char	*message;

	message = NULL;
	size_prop = read_size_prop();
	if (size_prop == 0)
		return ;
	ft_printf("size_prop: %i\n", size_prop); // TEMP
	// number of bytes in size (1-8)
	size = init_message(size_prop, &message);
	if (size == 0)
		return ;
	ft_printf("size: %i\n", size);    // TEMP
	kill(g_mess.pid, SIGNAL_SENDING); // TEMP
	// return pointer allocated memory
	// read_message(message, size, &signal);
	free(message);
}
