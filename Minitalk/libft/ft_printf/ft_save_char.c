/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:29:24 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/20 15:26:30 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_save_char(t_flags *flags, unsigned char c)
{
	flags->arg_len = 1;
	flags->str = (char *)ft_calloc(flags->arg_len + 1, sizeof(char));
	if (flags->str == NULL)
		return (0);
	*(flags->str) = c;
	return (1);
}
