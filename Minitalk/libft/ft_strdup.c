/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 00:21:32 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/30 22:39:23 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strdup() function returns a pointer to a new string which is a duplicate
// of the string s. Memory for the new string is obtained with malloc(3), and
// can be freed with free(3).
// RETURN VALUE: On success, the strdup() function returns a pointer to
// the duplicated string. It returns NULL if insufficient memory was available,
// with errno set to indicate the cause of the error.
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = (char *) malloc(sizeof (char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}
