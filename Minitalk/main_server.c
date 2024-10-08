/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:09:17 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/08 14:49:37 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char		g_message[2];

static void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_message[0] = g_message[0] * 2 + 1;
		g_message[1]++;
	}
	else if (signum == SIGUSR2)
	{
		g_message[0] = g_message[0] * 2;
		g_message[1]++;
	}
}

static void	set_signal(void)
{
	struct sigaction	action;
	sigset_t			mask;

	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	ft_bzero(&action, sizeof(action));
	action.sa_handler = &signal_handler;
	action.sa_mask = mask;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
}

int	main(void)
{
	ft_bzero(&g_message, sizeof(g_message));
	set_signal();
	ft_printf("%i\n", getpid());
	while (1)
	{
		pause();
		if (g_message[1] >= 8)
		{
			if (g_message[0] == 0)
			{
				write(1, "\n", 1);
			}
			write(1, g_message, 1);
			g_message[0] = 0;
			g_message[1] = 0;
		}
	}
}
