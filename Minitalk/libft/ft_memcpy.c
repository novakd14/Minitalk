/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:53:26 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/30 00:14:33 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memcpy() function copies n bytes from memory area src to memory area
// dest. The memory areas must not overlap.  Use memmove(3) if the memory areas
// do over‐lap.
// RETURN VALUE: The memcpy() function returns a pointer to dest.
// NOTES: Doesn't take NULL pointer and read-only strings for dest and NULL
// pointer for src!
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sptr;
	unsigned char	*dptr;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	sptr = (unsigned char *) src;
	dptr = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		*(dptr + i) = *(sptr + i);
		i++;
	}
	return (dest);
}
