/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:09:17 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/09 14:34:17 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_message	g_mess;

static void	load_message_size(int signum)
{
	if (signum == SIGUSR1)
	{
		g_mess.size = (g_mess.size << 1) + 1;
		g_mess.bite++;
	}
	else if (signum == SIGUSR2)
	{
		g_mess.size = g_mess.size << 1;
		g_mess.bite++;
	}
}

static void	malloc_buff(void)
{
	g_mess.message = (char *)calloc(g_mess.size + 1, sizeof(char));
	if (g_mess.message == NULL)
		exit(EXIT_FAILURE);
	*(g_mess.message + g_mess.size) = 0;
}

static void	signal_handler(int signum)
{
	if (g_mess.bite == 1)
		g_mess.recieving = TRUE;
	if (g_mess.bite == (int)sizeof(int) * 8 && g_mess.message == NULL)
		malloc_buff();
	if (g_mess.bite < (int)sizeof(int) * 8)
		load_message_size(signum);
	else if (g_mess.bite / 8 - (int)sizeof(int) < g_mess.size)
	{
		if (signum == SIGUSR1)
		{
			*(g_mess.message + g_mess.bite / 8 - sizeof(int)) *= 2;
			*(g_mess.message + g_mess.bite / 8 - sizeof(int)) += 1;
			g_mess.bite++;
		}
		else if (signum == SIGUSR2)
		{
			*(g_mess.message + g_mess.bite / 8 - sizeof(int)) *= 2;
			g_mess.bite++;
		}
	}
	if (g_mess.bite / 8 - (int)sizeof(int) == g_mess.size)
	{
		ft_printf("%s\n", g_mess.message);
		free(g_mess.message);
		ft_bzero(&g_mess, sizeof(g_mess));
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
	ft_bzero(&g_mess, sizeof(g_mess));
	set_signal();
	ft_printf("%i\n", getpid());
	while (1)
	{
		if (sleep(2) == 0 && g_mess.recieving == TRUE)
		{
			if (g_mess.message != NULL)
				free(g_mess.message);
			return (EXIT_FAILURE);
		}
		else
		{
			g_mess.recieving = TRUE;
			pause();
		}
	}
}
