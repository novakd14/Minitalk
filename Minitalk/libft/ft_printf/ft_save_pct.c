/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_pct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:29:57 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/19 03:10:32 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_save_pct(t_flags *flags)
{
	flags->field_width = 1;
	flags->arg_len = 1;
	flags->str = (char *)ft_calloc(flags->arg_len + 1, sizeof(char));
	if (flags->str == NULL)
		return (0);
	*(flags->str) = '%';
	return (1);
}
