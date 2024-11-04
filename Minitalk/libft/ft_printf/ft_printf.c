/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:42:50 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/21 11:56:11 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flags(t_flags *flags)
{
	flags->alter_form = 0;
	flags->zero_padd = 0;
	flags->left_adjust = 0;
	flags->space_signed = 0;
	flags->sign_signed = 0;
	flags->field_width = 0;
	flags->precision = -1;
	flags->str = NULL;
	flags->arg_len = 0;
}

int	ft_printf(const char *format, ...)
{
	int		len;
	size_t	i;
	va_list	argv;
	t_flags	flags;

	va_start(argv, format);
	len = 0;
	i = 0;
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			init_flags(&flags);
			if (ft_set_flags(format, &i, &flags, &argv) == 0)
				return (-1);
			len += ft_put_arg(&flags);
		}
		else
		{
			ft_putchar_fd(*(format + i++), 1);
			len++;
		}
	}
	va_end(argv);
	return (len);
}
