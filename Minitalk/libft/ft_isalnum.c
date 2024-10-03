/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:17:44 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 15:01:13 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// isalpha() checks for an alphabetic character; in the standard "C" locale, it
// is equivalent to (isupper(c) || islower(c)). In some locales, there may be
// additional characters for which isalpha() is true—letters which are neither
// uppercase nor lowercase.
// RETURN VALUE: The values returned are nonzero if the character c falls into
// the tested class, and zero if not.
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	return (0);
}
