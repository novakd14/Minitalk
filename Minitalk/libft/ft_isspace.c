/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:17:51 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/25 16:30:10 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// isspace() checks for white-space characters. In the "C" and "POSIX" locales,
// these are: space, form-feed ('\f'), newline ('\n'), carriage return ('\r'),
// horizontal tab('\t'), and vertical tab('\v').
// RETURN VALUE: The values returned are nonzero if the character c falls into
// the tested class, and zero if not.
int	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (c);
	return (0);
}
