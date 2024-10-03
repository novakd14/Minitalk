/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:38:09 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 01:22:18 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies the function f to each character of the string s, passing its index
// as the first argument and the character itself as the second. A new string
// is created (using malloc(3)) to collect the results from the successive
// applications of f.
// RETURN VALUE: The string created from the successive applications of ’f’.
// Returns NULL if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = (char *) ft_calloc(len + 1, sizeof (char));
	if (str == NULL)
		return (NULL);
	len = 0;
	while (*(s + len))
	{
		*(str + len) = f(len, *(s + len));
		len++;
	}
	*(str + len) = '\0';
	return (str);
}
