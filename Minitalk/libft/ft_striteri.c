/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:42:11 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/30 22:34:16 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies the function ’f’ on each character of the string passed as argument,
// passing its index as first argument. Each character is passed by address to
// ’f’ to be modified if necessary.
// RETURN VALUE: None
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;

	len = 0;
	while (*(s + len))
	{
		f(len, s + len);
		len++;
	}
}
