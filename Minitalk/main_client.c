/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:09:17 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/08 14:11:38 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_isnumber(char *num)
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

static void	end_message(int pid)
{
	int	bit_index;

	bit_index = 8;
	while (bit_index-- > 0)
	{
		kill(pid, SIGUSR2);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		bit_index;
	clock_t	time;

	if (argc != 3)
		return (1);
	if (!ft_isnumber(argv[1]))
		return (1);
	pid = ft_atoi(argv[1]);
	time = clock();
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
	end_message(pid);
	time = clock() - time;
	ft_printf("%u us\n", time);
	ft_printf("%u ms\n", time / 1000);
}
