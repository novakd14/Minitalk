/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:29:28 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/21 11:56:11 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_cpyprecision(t_flags *flags, char *dst)
{
	*dst = '.';
	ft_cpynbr(dst + 1, ft_checkunbr(flags->precision) - 1, flags->precision);
}

static void	ft_cpyflags(t_flags *flags, char *dst)
{
	int	i;
	int	len;

	*dst = '%';
	i = 1;
	if (flags->alter_form)
		*(dst + i++) = '#';
	if (flags->sign_signed)
		*(dst + i++) = '+';
	else if (flags->space_signed)
		*(dst + i++) = ' ';
	if (flags->left_adjust)
		*(dst + i++) = '-';
	else if (flags->zero_padd)
		*(dst + i++) = '0';
	if (flags->field_width > 0)
	{
		len = ft_checkunbr(flags->field_width);
		ft_cpynbr(dst + i, len - 1, flags->field_width);
		i += len;
	}
	if (flags->precision >= 0)
		ft_cpyprecision(flags, dst + i);
}

int	ft_save_flags(t_flags *flags)
{
	int	len;

	len = 1;
	if (flags->alter_form)
		len++;
	if (flags->sign_signed || flags->space_signed)
		len++;
	if (flags->left_adjust || flags->zero_padd)
		len++;
	if (flags->field_width > 0)
		len += ft_checkunbr(flags->field_width);
	if (flags->precision >= 0)
		len += 1 + ft_checkunbr(flags->precision);
	flags->arg_len = len;
	flags->str = (char *)ft_calloc(flags->arg_len + 1, sizeof(char));
	if (flags->str == NULL)
		return (0);
	ft_cpyflags(flags, flags->str);
	return (1);
}
