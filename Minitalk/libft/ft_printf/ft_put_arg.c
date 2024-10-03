/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:09:46 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/20 15:47:09 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long	ft_umin(unsigned long a, unsigned long b)
{
	if (a > b)
		return (b);
	return (a);
}

unsigned long	ft_umax(unsigned long a, unsigned long b)
{
	if (a < b)
		return (b);
	return (a);
}

long	ft_min(long a, long b)
{
	if (a > b)
		return (b);
	return (a);
}

long	ft_max(long a, long b)
{
	if (a < b)
		return (b);
	return (a);
}

int	ft_put_arg(t_flags *flags)
{
	int	padd;

	padd = flags->field_width;
	if (flags->left_adjust == 0)
	{
		while (padd > 0 && (unsigned)padd > flags->arg_len)
		{
			ft_putchar_fd(' ', 1);
			padd--;
		}
	}
	if (flags->str != NULL)
	{
		if (*(flags->str) == '\0' && flags->arg_len == 1)
			ft_putchar_fd('\0', 1);
		ft_putstr_fd(flags->str, 1);
		free(flags->str);
	}
	while (padd > 0 && (unsigned)padd > flags->arg_len)
	{
		ft_putchar_fd(' ', 1);
		padd--;
	}
	return (ft_umax(flags->field_width, flags->arg_len));
}
