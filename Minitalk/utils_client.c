/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:20:26 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/06 02:26:10 by dnovak           ###   ########.fr       */
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

// void	advanced_pause(void)
// {
// 	if (usleep(WAIT_TIME) != -1)
// 		ft_printf("NOTE: Waited for the whole usleep.\n");
// 	if (g_mess.used == TRUE)
// 		exit_message(EXIT_FAILURE,
// 			"ERROR: Did not recieve confirmation from server.\n");
// 	g_mess.used = TRUE;
// }

void	kill_with_check(pid_t pid, int signal, int status)
{
	int	time;

	if (signal == SIGNAL0)  // TEMP
		write(1, "0\n", 2); // TEMP
	else                    // TEMP
		write(1, "1\n", 2); // TEMP
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
