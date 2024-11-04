/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:10:00 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/04 18:54:57 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 199309L
# endif

# include "libft/libft.h" // ft_strlen(), ft_printf(), ft_calloc(), ft_bzero()
							//-> <stdlib.h> exit(), free(), EXIT_*
							//-> <unistd.h> get_pid(), write(), sleep(),
# include <signal.h>      // kill(), sigaction(), SIGUSR*
# include <sys/types.h>   // pid_t

typedef enum e_signal
{
	SIGNAL0 = SIGUSR1,
	SIGNAL1 = SIGUSR2,
}					t_sig;

typedef enum e_bool
{
	FALSE,
	TRUE,
}					t_bool;

typedef enum e_status
{
	WAITING,
	SIZE_PROP,
	SIZE,
	MESSAGE,
}					t_status;

typedef struct s_message
{
	t_status		status;
	size_t			size;
	int				size_prop;
	unsigned char	bytes[2];
	int				byte_num;
	size_t			bit_num;
}					t_message;

void				recieve_message(void);
void				exit_message(int status, char *message);

#endif // SERVER_H
