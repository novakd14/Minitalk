/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:29:51 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/21 11:56:11 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checknbr(int n)
{
	if (n > 0)
		n *= -1;
	if (n > -10)
		return (1);
	else
		return (1 + ft_checknbr(n / 10));
}

static void	ft_cpyint(t_flags *flags, char *dest, int len, int n)
{
	int	num_len;
	int	start;

	start = 0;
	num_len = ft_checknbr(n);
	if (n < 0)
		*dest = '-';
	else if (flags->sign_signed)
		*dest = '+';
	else if (flags->space_signed)
		*dest = ' ';
	if (n == 0 && flags->precision == 0)
		return ;
	if (flags->sign_signed || flags->space_signed || n < 0)
		start = 1;
	if (flags->zero_padd)
		ft_memset(dest + start, '0', ft_max(0, flags->field_width - num_len
				- start));
	else if (flags->precision >= 0)
		ft_memset(dest + start, '0', ft_max(0, flags->precision - num_len));
	ft_cpynbr(dest, len - 1, n);
}

int	ft_save_int(t_flags *flags, int n)
{
	size_t	len;

	if (n == 0 && flags->precision == 0)
	{
		if (flags->sign_signed || flags->space_signed)
			flags->arg_len = 1;
		else
			flags->arg_len = 0;
	}
	else
	{
		len = ft_checknbr(n);
		if (flags->precision >= 0)
			len = ft_umax(flags->precision, len);
		if (flags->sign_signed || flags->space_signed || n < 0)
			len += 1;
		if (flags->zero_padd)
			len = ft_umax(flags->field_width, len);
		flags->arg_len = len;
	}
	flags->str = (char *)ft_calloc(flags->arg_len + 1, sizeof(char));
	if (flags->str == NULL)
		return (0);
	ft_cpyint(flags, flags->str, flags->arg_len, n);
	return (1);
}
