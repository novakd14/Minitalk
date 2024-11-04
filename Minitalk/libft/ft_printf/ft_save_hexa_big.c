/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_hexa_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:29:41 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/21 11:59:25 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_cpyhexa_big(t_flags *flags, char *dest, int len, unsigned int x)
{
	int	num_len;
	int	start;

	if (x == 0 && flags->precision == 0)
		return ;
	start = 0;
	if (flags->alter_form && x != 0)
	{
		ft_strlcpy(dest, "0X", 3);
		start = 2;
	}
	num_len = ft_checkhexadec(x);
	if (flags->precision >= 0)
		ft_memset(dest + start, '0', ft_max(0, flags->precision - num_len));
	else if (flags->zero_padd)
		ft_memset(dest + start, '0', ft_max(0, flags->field_width - num_len
				- start));
	ft_cpyhexadec_big(dest, len - 1, x);
}

int	ft_save_hexa_big(t_flags *flags, unsigned int x)
{
	size_t	len;

	if (x == 0 && flags->precision == 0)
		flags->arg_len = 0;
	else
	{
		len = ft_checkhexadec(x);
		if (flags->precision >= 0)
			len = ft_umax(flags->precision, len);
		if (flags->alter_form && x != 0)
			len += 2;
		if (flags->zero_padd)
			len = ft_umax(flags->field_width, len);
		flags->arg_len = len;
	}
	flags->str = (char *)ft_calloc(flags->arg_len + 1, sizeof(char));
	if (flags->str == NULL)
		return (0);
	ft_cpyhexa_big(flags, flags->str, flags->arg_len, x);
	return (1);
}
