/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:53:12 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/21 15:56:46 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memmove() function copies n bytes from memory area src to memory area
// dest. The memory areas may overlap: copying takes place as though the bytes
// in src are first copied into a temporary array that does not overlap src or
// dest, and the bytes are then copied from the temporary array to dest.
// RETURN VALUE: The memmove() function returns a pointer to dest.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	size_t			i;

	if (dest == NULL || src == NULL)
		return (dest);
	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	if (src >= dest)
	{
		i = 0;
		while (i < n)
		{
			*(dptr + i) = *(sptr + i);
			i++;
		}
	}
	else
		while (n-- > 0)
			*(dptr + n) = *(sptr + n);
	return (dest);
}
