/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:14:54 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/10 00:02:47 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "../libft.h"
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

typedef struct s_flags
{
	char		alter_form;
	char		zero_padd;
	char		left_adjust;
	char		space_signed;
	char		sign_signed;
	int			field_width;
	int			precision;
	char		*str;
	size_t		arg_len;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_set_flags(const char *format, size_t *i, t_flags *flags,
					va_list *argv);

// Functions for saving argument to string
int				ft_save_char(t_flags *flags, unsigned char c);
int				ft_save_str(t_flags *flags, char *c);
int				ft_save_ptr(t_flags *flags, void *ptr);
int				ft_save_int(t_flags *flags, int n);
int				ft_save_uint(t_flags *flags, unsigned int n);
int				ft_save_hexa_small(t_flags *flags, unsigned int x);
int				ft_save_hexa_big(t_flags *flags, unsigned int x);
int				ft_save_pct(t_flags *flags);
int				ft_save_flags(t_flags *flags);
void			ft_cpyhexadec_small(char *dest, int len, unsigned long x);
void			ft_cpyhexadec_big(char *dest, int len, unsigned long x);
void			ft_cpynbr(char *dest, int last, int n);

// Print argument
int				ft_put_arg(t_flags *flags);

// Useful functions
int				ft_checkhexadec(unsigned long int x);
int				ft_checkunbr(unsigned int u);
unsigned long	ft_umin(unsigned long a, unsigned long b);
unsigned long	ft_umax(unsigned long a, unsigned long b);
long			ft_min(long a, long b);
long			ft_max(long a, long b);

#endif // LIBFTPRINTF_H
