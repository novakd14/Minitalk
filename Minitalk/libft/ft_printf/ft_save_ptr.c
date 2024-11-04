/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:30:01 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/21 11:56:11 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_cpyptr(char *dest, int len, void *ptr)
{
	ft_strlcpy(dest, "0x", 3);
	ft_cpyhexadec_small(dest, len - 1, (unsigned long)ptr);
}

int	ft_save_ptr(t_flags *flags, void *ptr)
{
	if (ptr == NULL)
	{
		flags->arg_len = 5;
		flags->str = (char *)ft_calloc(flags->arg_len + 1, sizeof(char));
		if (flags->str == NULL)
			return (0);
		ft_strlcpy(flags->str, "(nil)", flags->arg_len + 1);
		return (1);
	}
	flags->arg_len = 2 + ft_checkhexadec((unsigned long)ptr);
	flags->str = (char *)ft_calloc(flags->arg_len + 1, sizeof(char));
	if (flags->str == NULL)
		return (0);
	ft_cpyptr(flags->str, flags->arg_len, ptr);
	return (1);
}
