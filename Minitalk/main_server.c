/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:09:17 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/06 02:28:07 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_message	g_mess;

void	exit_message(int status, char *message)
{
	if (status == EXIT_SUCCESS)
		ft_putstr_fd(message, STDOUT_FILENO);
	else
		ft_putstr_fd(message, STDERR_FILENO);
	exit(status);
}

static void	signal_action(int signal, siginfo_t *info, void *ucontext)
{
	g_mess.recieved = TRUE;
	g_mess.pid = info->si_pid;
	if (signal == SIGNAL0)
		g_mess.bit = 0;
	else
		g_mess.bit = 1;
	(void)ucontext;
	if (signal == SIGNAL0)  // TEMP
		write(1, "0\n", 2); // TEMP
	else                    // TEMP
		write(1, "1\n", 2); // TEMP
}

static void	init_signals(void)
{
	struct sigaction	sa;
	sigset_t			mask;

	if (sigemptyset(&mask) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not initialize mask.\n");
	if (sigaddset(&mask, SIGNAL0) == -1 || sigaddset(&mask, SIGNAL1) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not add a signal to mask.\n");
	sa.sa_sigaction = &signal_action;
	sa.sa_mask = mask;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGNAL0, &sa, NULL) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not set a signal action.\n");
	if (sigaction(SIGNAL1, &sa, NULL) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not set a signal action.\n");
}

int	main(void)
{
	init_signals();
	ft_printf("%i\n", getpid());
	while (TRUE)
	{
		recieve_message();
		ft_printf("NOTE: Message recieved.\n"); // TEMP
	}
	return (EXIT_SUCCESS);
}
