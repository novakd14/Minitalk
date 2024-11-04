/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:16:08 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/25 20:11:52 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// isupper() checks for an uppercase letter.
// RETURN VALUE The values returned are nonzero if the character c falls into
// the tested class, and zero if not.
int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c);
	return (0);
}
