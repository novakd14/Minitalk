/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:09:17 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/06 12:39:45 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

sig_atomic_t	g_status;

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

static void	send_message(int pid, char *mess)
{
	int	i;
	int	bit_check;

	i = 0;
	while (*(mess + i) != '\0')
	{
		bit_check = 1 << 7;
		while (bit_check != 0)
		{
			if ((*(mess + i) & bit_check) == 0)
				kill_with_check(pid, SIGNAL0, RECIEVED);
			else
				kill_with_check(pid, SIGNAL1, RECIEVED);
			bit_check >>= 1;
		}
		i++;
	}
}

static void	end_message(int pid)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		kill_with_check(pid, SIGNAL0, RECIEVED);
		i++;
	}
	kill_with_check(pid, SIGNAL0, FINISH);
}

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
	send_message_size(pid, ft_strlen(argv[2]) + 1);
	send_message(pid, argv[2]);
	end_message(pid);
	return (EXIT_SUCCESS);
}
