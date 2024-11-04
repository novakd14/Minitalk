/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:14:54 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/21 15:45:50 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft.h" // bzero, memchr, memmove
# include <stdlib.h>   // malloc, free
# include <unistd.h>   // read
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef struct s_buf
{
	int				fd;
	char			*buf;
	ssize_t			size;
	char			*end_char;
	struct s_buf	*next;
}					t_buf;

// Utility functions
t_buf				*ft_bufnew(int fd);
void				ft_bufdel(t_buf **list, int fd);

#endif // GET_NEXT_LINE_H
