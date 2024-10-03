/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:30:10 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/19 15:52:53 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_cpyunbr(char *dest, int last, unsigned int n)
{
	if (n < 10)
		*(dest + last) = '0' + n;
	else
	{
		*(dest + last) = '0' + n % 10;
		ft_cpyunbr(dest, last - 1, n / 10);
	}
}

static void	ft_cpyuint(t_flags *flags, char *dest, int len, unsigned int n)
{
	int	num_len;

	num_len = ft_checkunbr(n);
	if (n == 0 && flags->precision == 0)
		return ;
	if (flags->precision >= 0)
		ft_memset(dest, '0', ft_max(0, flags->precision - num_len));
	else if (flags->zero_padd)
		ft_memset(dest, '0', ft_max(0, flags->field_width - num_len));
	ft_cpyunbr(dest, len - 1, n);
}

int	ft_save_uint(t_flags *flags, unsigned int n)
{
	size_t	len;

	if (n == 0 && flags->precision == 0)
		flags->arg_len = 0;
	else
	{
		len = ft_checkunbr(n);
		if (flags->precision >= 0)
			len = ft_umax(flags->precision, len);
		else if (flags->zero_padd)
			len = ft_umax(flags->field_width, len);
		flags->arg_len = len;
	}
	flags->str = (char *)ft_calloc(flags->arg_len + 1, sizeof(char));
	if (flags->str == NULL)
		return (0);
	ft_cpyuint(flags, flags->str, flags->arg_len, n);
	return (1);
}
