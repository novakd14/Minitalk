/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:25:59 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/26 23:15:13 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The atoi() function converts the initial portion of the string pointed to by
// nptr to int. The behavior is the same as strtol(nptr, NULL, 10); except
// that atoi() does not detect errors. The string may begin with an arbitrary
// amount of white space (as determined by isspace(3)) followed by a single
// optional '+' or '-' sign.
// RETURN VALUE: The converted value or 0 on error.
// NOTES: If ntpr == NULL return Segmentation fault
int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		num;

	i = 0;
	while (ft_isspace(*(nptr + i)))
		i++;
	sign = 1;
	if (*(nptr + i) == '+' || *(nptr + i) == '-')
		if (*(nptr + i++) == '-')
			sign = -1;
	num = 0;
	while (ft_isdigit(*(nptr + i)))
		num = num * 10 + *(nptr + i++) - '0';
	return (num * sign);
}
