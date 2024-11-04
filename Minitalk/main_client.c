/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:09:17 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/04 12:58:08 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static t_bool	ft_ispid(char *num)
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
		kill_with_check(pid, SIGNAL1);
	kill_with_check(pid, SIGNAL0);
	while (bit_check != 0)
	{
		if ((size & bit_check) == 0)
			kill_with_check(pid, SIGNAL0);
		else
			kill_with_check(pid, SIGNAL1);
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
				kill_with_check(pid, SIGNAL0);
			else
				kill_with_check(pid, SIGNAL1);
			bit_check >>= 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		exit_message(EXIT_FAILURE,
			"ERROR: Wrong number of parameters.\n Use: ./client PID message\n");
	if (ft_ispid(argv[1]) == FALSE)
		exit_message(EXIT_FAILURE, "ERROR: Pass a valid PID number.\n");
	pid = ft_atoi(argv[1]);
	send_message_size(pid, ft_strlen(argv[2]));
	send_message(pid, argv[2]);
	return (EXIT_SUCCESS);
}
