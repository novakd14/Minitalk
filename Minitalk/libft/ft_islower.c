/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:16:08 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/25 20:12:29 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// islower() checks for an lowercase letter.
// RETURN VALUE The values returned are nonzero if the character c falls into
// the tested class, and zero if not.
int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c);
	return (0);
}
