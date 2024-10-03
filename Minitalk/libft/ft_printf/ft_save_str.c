/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:30:06 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/19 15:46:29 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_save_str(t_flags *flags, char *s)
{
	size_t	len;

	if (s == NULL)
	{
		if (flags->precision >= 0 && flags->precision < 6)
			flags->arg_len = 0;
		else
			flags->arg_len = 6;
		flags->str = (char *)ft_calloc(flags->arg_len + 1, sizeof(char));
		if (flags->str == NULL)
			return (0);
		ft_strlcpy(flags->str, "(null)", flags->arg_len + 1);
		return (1);
	}
	len = ft_strlen(s);
	if (flags->precision >= 0 && (unsigned)flags->precision < len)
		flags->arg_len = flags->precision;
	else
		flags->arg_len = len;
	flags->str = (char *)ft_calloc(flags->arg_len + 1, sizeof(char));
	if (flags->str == NULL)
		return (0);
	ft_strlcpy(flags->str, s, flags->arg_len + 1);
	return (1);
}
