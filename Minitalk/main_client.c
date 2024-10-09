/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:09:17 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/09 14:35:26 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	ft_isnumber(char *num)
{
	if (num == NULL || *num == 0)
		return (0);
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

static void	send_message_size(int pid, int size)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index++ < (int)sizeof(int) * 8)
	{
		if (size & (1 << (sizeof(int) * 8 - 1)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		size = size << 1;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	bit_index;

	if (argc != 3)
		return (1);
	if (!ft_isnumber(argv[1]))
		return (1);
	pid = ft_atoi(argv[1]);
	send_message_size(pid, ft_strlen(argv[2]));
	while (*(argv[2]) != 0)
	{
		bit_index = 8;
		while (bit_index-- > 0)
		{
			if (*(argv[2]) & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			*(argv[2]) = *(argv[2]) << 1;
			usleep(500);
		}
		argv[2]++;
	}
}
