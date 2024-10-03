/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:23:53 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/30 22:06:34 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strrchr() function returns a pointer to the last occurrence of
// the character c in the string s.
// RETURN VALUE: The strchr() and strrchr() functions return a pointer to
// the matched character or NULL if the character is not found. The terminating
// null byte is considered part of the string, so that if c is specified as
// '\0', these functions return a pointer to the terminator.
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (*(s + len - i) == (char) c)
			return ((char *) s + len - i);
		i++;
	}
	return (NULL);
}
