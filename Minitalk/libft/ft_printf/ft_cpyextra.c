/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyextra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:00:40 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/19 03:02:21 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_cpyhexadec_small(char *dest, int last, unsigned long x)
{
	if (x < 10)
		*(dest + last) = '0' + x;
	else if (x < 16)
		*(dest + last) = 'a' + x - 10;
	else
	{
		ft_cpyhexadec_small(dest, last - 1, x / 16);
		if (x % 16 < 10)
			*(dest + last) = '0' + x % 16;
		else
			*(dest + last) = 'a' + x % 16 - 10;
	}
}

void	ft_cpyhexadec_big(char *dest, int last, unsigned long x)
{
	if (x < 10)
		*(dest + last) = '0' + x;
	else if (x < 16)
		*(dest + last) = 'A' + x - 10;
	else
	{
		ft_cpyhexadec_big(dest, last - 1, x / 16);
		if (x % 16 < 10)
			*(dest + last) = '0' + x % 16;
		else
			*(dest + last) = 'A' + x % 16 - 10;
	}
}

void	ft_cpynbr(char *dest, int last, int n)
{
	if (n > 0)
		n *= -1;
	if (n > -10)
		*(dest + last) = '0' - n;
	else
	{
		*(dest + last) = '0' - n % 10;
		ft_cpynbr(dest, last - 1, n / 10);
	}
}

int	ft_checkunbr(unsigned int u)
{
	if (u < 10)
		return (1);
	else
		return (1 + ft_checkunbr(u / 10));
}

int	ft_checkhexadec(unsigned long int x)
{
	if (x < 16)
		return (1);
	else
		return (1 + ft_checkhexadec(x / 16));
}
