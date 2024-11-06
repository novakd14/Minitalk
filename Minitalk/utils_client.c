/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:20:26 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/06 12:45:01 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern sig_atomic_t	g_status;

t_bool	ft_ispid(char *num)
{
	size_t	i;

	if (*num == '\0')
		return (FALSE);
	i = 0;
	while (*(num + i) != '\0')
	{
		if (ft_isdigit(*(num + i)) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	signal_handler(int signal)
{
	if (signal == SIGNAL_SENDING)
		g_status = RECIEVED;
	else
		g_status = FINISH;
}

void	init_signals(void)
{
	struct sigaction	sa;
	sigset_t			mask;

	if (sigemptyset(&mask) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not initialize mask.\n");
	if (sigaddset(&mask, SIGNAL_SENDING) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not add signal to mask.\n");
	if (sigaddset(&mask, SIGNAL_FINISH) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not add signal to mask.\n");
	sa.sa_handler = &signal_handler;
	sa.sa_mask = mask;
	sa.sa_flags = 0;
	if (sigaction(SIGNAL_SENDING, &sa, NULL) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not set a signal action.\n");
	if (sigaction(SIGNAL_FINISH, &sa, NULL) == -1)
		exit_message(EXIT_FAILURE, "ERROR: Could not set a signal action.\n");
}

void	kill_with_check(pid_t pid, int signal, int status)
{
	int	time;

	if (kill(pid, signal) == -1)
		exit_message(EXIT_FAILURE,
			"ERROR: Could not send message. Signal was not recieved.\n");
	time = 0;
	while (g_status == WAITING)
	{
		if (time > WAIT_TIME)
			exit_message(EXIT_FAILURE,
				"ERROR: Did not recieve confirmation from server.\n");
		time += TIME_STEP;
		usleep(TIME_STEP);
	}
	if (g_status != status)
		exit_message(EXIT_FAILURE,
			"ERROR: Server did not recieve full message.\n");
	g_status = WAITING;
}

void	exit_message(int status, char *message)
{
	size_t	len;

	len = ft_strlen(message);
	if (status == EXIT_SUCCESS)
		write(STDOUT_FILENO, message, len);
	else
		write(STDERR_FILENO, message, len);
	exit(status);
}
