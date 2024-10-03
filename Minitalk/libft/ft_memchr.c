/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:53:42 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 23:37:08 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memchr() function scans the initial n bytes of the memory area pointed
// to by s for the first instance of c. Both c and the bytes of the memory area
// pointed to by s are interpreted as unsigned char.
// RETURN VALUE: The memchr() and memrchr() functions return a pointer to the
// matching byte or NULL if the character does not occur in the given memory
// area.
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*(ptr + i) == (unsigned char) c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
