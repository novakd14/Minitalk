/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:17:53 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 16:32:10 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// isprint() checks for any printable character including space.
// RETURN VALUE The values returned are nonzero if the character c falls into
// the tested class, and zero if not.
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
