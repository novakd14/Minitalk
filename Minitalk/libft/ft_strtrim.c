/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:36:15 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 05:08:50 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (ft_strchr(set, *(s1 + start)) != NULL && *(s1 + start))
		start++;
	return (start);
}

static size_t	ft_get_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1);
	if (end != 0)
		end--;
	while (end > 0 && ft_strchr(set, *(s1 + end)) != NULL)
		end--;
	return (end);
}

// Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
// specified in ’set’ removed from the beginning and the end of the string.
// RETURN VALUE: The trimmed string. NULL if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	if (end == 0)
		len = 0;
	else
		len = end - start + 1;
	str = (char *) ft_calloc(len + 1, sizeof (char));
	if (str == NULL)
		return (NULL);
	len--;
	while (end >= start && end > 0)
		*(str + len--) = *(s1 + end--);
	*str = *(s1 + start);
	return (str);
}
