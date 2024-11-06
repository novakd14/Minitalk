/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:54 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/06 12:45:23 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

extern t_message	g_mess;

static void	signal_action(int signal, siginfo_t *info, void *ucontext)
{
	g_mess.recieved = TRUE;
	g_mess.pid = info->si_pid;
	if (signal == SIGNAL0)
		g_mess.bit = 0;
	else
		g_mess.bit = 1;
	(void)ucontext;
}

void	init_signals(void)
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

void	exit_message(int status, char *message)
{
	if (status == EXIT_SUCCESS)
		ft_putstr_fd(message, STDOUT_FILENO);
	else
		ft_putstr_fd(message, STDERR_FILENO);
	exit(status);
}
