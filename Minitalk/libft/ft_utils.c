/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:34:55 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/29 01:37:30 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

long	ft_abs(long a)
{
	if (a < 0)
		return (-a);
	return (a);
}
