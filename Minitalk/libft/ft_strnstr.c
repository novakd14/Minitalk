/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:03:25 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 02:01:13 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strnstr() function locates the first occurrence of the null-terminated
// string little in the string big, where not more than len characters are
// searched. Characters that appear after a ‘\0’ character are not searched.
// Since the strnstr() function is a FreeBSD specific API, it should only be
// used when portability is not a concern.
// RETURN VALUES: If little is an empty string, big is returned; if little
// occurs nowhere in big, NULL is returned; otherwise a pointer to the first
// character of the first occurrence of little is returned.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;
	size_t	i;
	size_t	j;

	l_len = ft_strlen(little);
	if (l_len == 0)
		return ((char *) big);
	i = 0;
	while (i < len && *(big + i))
	{
		if (*(big + i) == *little)
		{
			j = 1;
			while (i + l_len <= len && *(big + i + j) == *(little + j)
				&& *(little + j))
				j++;
			if (j == l_len)
				return ((char *) big + i);
		}
		i++;
	}
	return (NULL);
}
