/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:17:48 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 16:23:22 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// isascii() checks whether c is a 7-bit unsigned char value that fits into
// the ASCII character set.
// RETURN VALUE The values returned are nonzero if the character c falls into
// the tested class, and zero if not.
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
