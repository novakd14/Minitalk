/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:09:17 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/06 02:28:54 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

sig_atomic_t	g_status;

static void	signal_handler(int signal)
{
	if (signal == SIGNAL_SENDING)
		g_status = RECIEVED;
	else
		g_status = FINISH;
}

static void	init_signals(void)
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

static void	send_message_size(pid_t pid, size_t size)
{
	size_t	num;
	int		bit_pos;
	int		byte;
	size_t	bit_check;

	num = size;
	bit_pos = 0;
	while (num != 0)
	{
		num >>= 1;
		bit_pos += 1;
	}
	byte = (bit_pos - 1) / 8;
	bit_check = (size_t)1 << ((byte + 1) * 8 - 1);
	while (byte-- > 0)
		kill_with_check(pid, SIGNAL1, RECIEVED);
	kill_with_check(pid, SIGNAL0, RECIEVED);
	while (bit_check != 0)
	{
		if ((size & bit_check) == 0)
			kill_with_check(pid, SIGNAL0, RECIEVED);
		else
			kill_with_check(pid, SIGNAL1, RECIEVED);
		bit_check >>= 1;
	}
}

// static void	send_message(int pid, char *mess)
// {
// 	int	i;
// 	int	bit_check;

// 	i = 0;
// 	while (*(mess + i) != '\0')
// 	{
// 		bit_check = 1 << 7;
// 		while (bit_check != 0)
// 		{
// 			if ((*(mess + i) & bit_check) == 0)
// 				kill_with_check(pid, SIGNAL0, g_confirm);
// 			else
// 				kill_with_check(pid, SIGNAL1, g_confirm);
// 			bit_check >>= 1;
// 		}
// 		write(1, mess + i, 1);
// 		i++;
// 	}
// }

// static void	end_message(int pid)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		kill_with_check(pid, SIGNAL0, g_confirm);
// 		i++;
// 	}
// }

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		exit_message(EXIT_FAILURE,
			"ERROR: Wrong number of parameters.\n Use: ./client PID message\n");
	if (ft_ispid(argv[1]) == FALSE)
		exit_message(EXIT_FAILURE, "ERROR: Pass a valid PID number.\n");
	init_signals();
	pid = ft_atoi(argv[1]);
	send_message_size(pid, ft_strlen(argv[2]) + 1); // add 1 for '\0' character
	ft_printf("NOTE: Message size send.\n");        // TEMP
	// send_message(pid, argv[2]);
	// end_message(pid);
	return (EXIT_SUCCESS);
}
