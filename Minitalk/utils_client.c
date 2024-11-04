/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:20:26 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/04 12:58:12 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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

void	kill_with_check(pid_t pid, int signal)
{
	if (kill(pid, signal) == -1)
		exit_message(EXIT_FAILURE,
			"ERROR: Could not send message. Signal was not recieved.\n");
	usleep(WAIT_TIME);
}
