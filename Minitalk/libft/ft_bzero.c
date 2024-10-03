/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:55:12 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 23:47:07 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The bzero() function erases the data in the n bytes of the memory starting
// at the location pointed to by s, by writing zeros (bytes containing '\0') to
// that area.
// RETURN VALUE: None.
// NOTES: Doesn't take NULL pointer and read-only strings!
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
		*(ptr + i++) = '\0';
}
