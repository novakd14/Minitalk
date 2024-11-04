/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:41:41 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/21 11:56:11 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_flags(char c, t_flags *flags)
{
	if (c == '#')
		flags->alter_form = 1;
	else if (c == '0' && flags->left_adjust == 0)
		flags->zero_padd = 1;
	else if (c == '-')
	{
		flags->left_adjust = 1;
		flags->zero_padd = 0;
	}
	else if (c == ' ')
		flags->space_signed = 1;
	else if (c == '+')
		flags->sign_signed = 1;
	else
		return (0);
	return (1);
}

static int	ft_check_conv_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

static void	check_precision(const char *format, size_t *i, t_flags *flags)
{
	*i += 1;
	if (ft_isdigit(*(format + *i)))
	{
		flags->precision = ft_atoi(format + *i);
		while (*(format + *i) && ft_isdigit(*(format + *i)))
			*i += 1;
	}
	else
		flags->precision = 0;
	if (flags->precision >= 0)
		flags->zero_padd = 0;
}

static int	ft_save_arg(char c, t_flags *flags, va_list *argv)
{
	int	check;

	check = 1;
	if (c == 'c')
		check = ft_save_char(flags, va_arg(*argv, int));
	else if (c == 's')
		check = ft_save_str(flags, va_arg(*argv, char *));
	else if (c == 'p')
		check = ft_save_ptr(flags, va_arg(*argv, void *));
	else if (c == 'd' || c == 'i')
		check = ft_save_int(flags, va_arg(*argv, int));
	else if (c == 'u')
		check = ft_save_uint(flags, va_arg(*argv, unsigned int));
	else if (c == 'x')
		check = ft_save_hexa_small(flags, va_arg(*argv, unsigned int));
	else if (c == 'X')
		check = ft_save_hexa_big(flags, va_arg(*argv, unsigned int));
	else if (c == '%')
		check = ft_save_pct(flags);
	return (check);
}

int	ft_set_flags(const char *format, size_t *i, t_flags *flags,
		va_list *argv)
{
	*i += 1;
	while (ft_check_flags(*(format + *i), flags))
		*i += 1;
	flags->field_width = ft_atoi(format + *i);
	while (ft_isdigit(*(format + *i)))
		*i += 1;
	if (*(format + *i) == '.')
		check_precision(format, i, flags);
	if (ft_check_conv_spec(*(format + *i)))
	{
		if (ft_save_arg(*(format + *i), flags, argv) == 0)
			return (0);
		*i += 1;
	}
	else
	{
		if (ft_save_flags(flags) == 0)
			return (0);
	}
	return (1);
}
