/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:33:13 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/31 16:14:10 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(const char *nptr, size_t *i)
{
	if (*nptr == '+' || *nptr == '-')
	{
		*i += 1;
		if (*nptr == '-')
			return (-1);
	}
	return (1);
}

static int	check_base(int base, const char *nptr, size_t *i)
{
	if (base == 0)
	{
		if (ft_strncmp(nptr, "0x", 2) == 0 || ft_strncmp(nptr, "0X", 2) == 0)
		{
			base = 16;
			*i += 2;
		}
		else if (*nptr == '0')
		{
			base = 8;
			*i += 1;
		}
		else
			base = 10;
	}
	else if (base == 16)
	{
		if (ft_strncmp(nptr, "0x", 2) == 0 || ft_strncmp(nptr, "0X", 2) == 0)
			*i += 2;
	}
	else if (base < 0 || base == 1 || base > 36)
		return (-1);
	return (base);
}

static int	ft_isbase(int c, int base)
{
	if (c >= '0' && c <= '0' + ft_min(base - 1, 9))
		return (c);
	if (c >= 'A' && c <= 'A' + base - 11)
		return (c);
	if (c >= 'a' && c <= 'a' + base - 11)
		return (c);
	return (0);
}

static long	new_num(long num, int sign, int c, int base)
{
	int	add;

	if ((num == __LONG_MAX__ && sign == 1) || num < 0)
		return (num);
	if (num > __LONG_MAX__ / base && sign == 1)
		return (__LONG_MAX__);
	if (num > __LONG_MAX__ / base && sign == -1)
		return (-__LONG_MAX__ - 1);
	num *= base;
	if (ft_isdigit(c))
		add = c - '0';
	else if (ft_isupper(c))
		add = c - 'A' + 10;
	else if (ft_islower(c))
		add = c - 'a' + 10;
	else
		add = 0;
	if (num >= __LONG_MAX__ - add && sign == 1)
		return (__LONG_MAX__);
	if (num > __LONG_MAX__ - add && sign == -1)
		return (-__LONG_MAX__ - 1);
	return (num + add);
}

// The strtol(void) function converts the initial part of the string in nptr to
// a long integer value according to the given base, which must be between
// 2 and 36 inclusive, or be the special value 0.

// The string may begin with an arbitrary amount of white space(as determined
// by isspace(3)) followed by a single optional '+' or '-' sign.If base is zero
// or 16, the string may then include a "0x" or "0X" prefix, and the number
// will be read in base 16; otherwise, a zero base is taken as 10(decimal)
// unless the next character is '0', in which case it is taken as 8(octal).

// The remainder of the string is converted to a long value in the obvious
// manner, stopping at the first character which is not a valid digit in the
// given base.(In bases above 10, the letter 'A' in either uppercase or
// lowercase represents 10, 'B' represents 11, and so forth, with 'Z'
// representing 35.)

// If endptr is not NULL, strtol() stores the address of the first invalid
// character in *endptr. If there were no digits at all, strtol() stores
// the original value of nptr in *endptr (and returns 0). In particular,
// if *nptr is not '\0' but **endptr is '\0' on return, the entire string is
// valid.
long	ft_strtol(const char *nptr, char **endptr, int base)
{
	size_t	i;
	int		sign;
	long	num;

	if (nptr == NULL)
		return (0);
	i = 0;
	while (ft_isspace(*(nptr + i)))
		i++;
	sign = check_sign(nptr + i, &i);
	base = check_base(base, nptr + i, &i);
	if (base < 0)
		return (0);
	num = 0;
	while (ft_isbase(*(nptr + i), base))
		num = new_num(num, sign, *(nptr + i++), base);
	if (endptr != NULL)
		*endptr = (char *)nptr + i;
	if (num < 0)
		return (num);
	return (num * sign);
}
