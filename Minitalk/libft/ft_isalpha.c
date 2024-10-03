/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:16:08 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 16:16:00 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// isalpha() checks for an alphabetic character; in the standard "C" locale, it
// is equivalent to (isupper(c) || islower(c)). In some locales, there may be
// additional characters for which isalpha() is true—letters which are neither
// uppercase nor lowercase.
// RETURN VALUE The values returned are nonzero if the character c falls into
// the tested class, and zero if not.
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	return (0);
}
