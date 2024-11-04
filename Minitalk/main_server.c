/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:09:17 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/04 18:54:41 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_message	g_mess;

static void	signal_handler(int signal)
{
	int	byte;

	if (g_mess.status == WAITING)
		g_mess.status = SIZE_PROP;
	if (g_mess.status == SIZE_PROP)
	{
		if (signal == SIGNAL1)
			g_mess.bit_num++;
		else
		{
			g_mess.size_prop = g_mess.bit_num;
			g_mess.bit_num = 0;
			g_mess.status = SIZE;
		}
	}
	else
	{
		byte = (g_mess.bit_num / 8) % 2;
		g_mess.bytes[byte] <<= 1;
		if (signal == SIGNAL1)
			g_mess.bytes[byte] += 1;
		g_mess.bit_num++;
	}
}

static void	init_signals(void)
{
	sigset_t			sa_mask;
	struct sigaction	sa;

	if (sigemptyset(&sa_mask) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not initialize mask.\n");
	if (sigaddset(&sa_mask, SIGNAL0) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not initialize mask.\n");
	if (sigaddset(&sa_mask, SIGNAL1) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not initialize mask.\n");
	sa.sa_handler = &signal_handler;
	sa.sa_mask = sa_mask;
	sa.sa_flags = 0;
	if (sigaction(SIGNAL0, &sa, NULL) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not set a signal action.\n");
	if (sigaction(SIGNAL1, &sa, NULL) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not set a signal action.\n");
}

int	main(void)
{
	g_mess.size_prop = -1;
	init_signals();
	ft_printf("%i\n", getpid());
	while (TRUE)
	{
		pause();
		recieve_message();
	}
	return (EXIT_SUCCESS);
}
