/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:48:59 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 03:47:50 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Can be used with ft_strlcpy? Seems like unnecessary looping through string.
// Allocates (with malloc(3)) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.
// RETURN VALUE: The substring. NULL if the allocation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	min_len;

	min_len = 0;
	if (start < ft_strlen(s))
		while (*(s + start + min_len) && min_len < len)
			min_len++;
	sstr = (char *) malloc(sizeof (char) * (min_len + 1));
	if (sstr == NULL)
		return (NULL);
	min_len = 0;
	if (start < ft_strlen(s))
	{
		while (*(s + start + min_len) && min_len < len)
		{
			*(sstr + min_len) = *(s + start + min_len);
			min_len++;
		}
	}
	*(sstr + min_len) = '\0';
	return (sstr);
}
