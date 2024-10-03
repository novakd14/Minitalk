/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:47:07 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 01:01:51 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	len;

	len = 0;
	count = 0;
	while (*(s + len))
	{
		while (*(s + len) != c && *(s + len))
			len++;
		count++;
		while (*(s + len) == c && *(s + len))
			len++;
	}
	return (count);
}

static size_t	ft_strlen_del(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	return (len);
}

static int	ft_check_array(char **array, size_t max_i)
{
	size_t	i;

	if (*(array + max_i) != NULL)
	{
		**(array + max_i) = '\0';
		return (1);
	}
	i = 0;
	while (i < max_i)
		free(*(array + i++));
	free(array);
	return (0);
}

static char	**ft_pop_array(char **array, char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		len = ft_strlen_del(s + i, c);
		*(array + count) = (char *) ft_calloc(len + 1, sizeof (char));
		if (ft_check_array(array, count) == 0)
			return (NULL);
		ft_strlcpy(*(array + count++), s + i, len + 1);
		i += len;
		while (*(s + i) == c && *(s + i))
			i++;
	}
	return (array);
}

// Not happy with it!
// Allocates (with malloc(3)) and returns an array of strings obtained by
// splitting ’s’ using the character ’c’ as a delimiter. The array must end
// with a NULL pointer.
// RETURN VALUE: The array of new strings resulting from the split. NULL if the
// allocation fails.
char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	skip;
	char	**array;

	skip = 0;
	while (*(s + skip) == c && *(s + skip))
		skip++;
	count = ft_count_words(s + skip, c);
	array = (char **) ft_calloc(count + 1, sizeof (char *));
	if (array == NULL)
		return (NULL);
	*(array + count) = NULL;
	return (ft_pop_array(array, s + skip, c));
}
