/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:53:52 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/30 23:21:55 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The calloc() function allocates memory for an array of nmemb elements of
// size bytes each and returns a pointer to the allocated memory. The memory is
// set to zero. If nmemb or size is 0, then calloc() returns either NULL, or
// a unique pointer value that can later be successfully passed to free().
// If the multiplication of nmemb and size would result in integer overflow,
// then calloc() returns an error. By contrast, an integer overflow would not
// be detected in the following call to malloc(), with the result that
// an incorrectly sized block of memory would be allocated:
// malloc(nmemb * size);
// RETURN VALUE: The calloc() function returns a pointer to the allocated
// memory, which is suitably aligned for any built-in type. On error, this
// function returns NULL. NULL may also be returned by a successful call to
// calloc() with nmemb or size equal to zero.
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 0;
	}
	if (9223372036854775807 / nmemb < size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
