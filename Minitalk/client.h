/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:10:00 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/06 01:29:17 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

// FOR: usleep()
# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif

// FOR: signals
# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE
# endif

# include "libft/libft.h" // ft_isdigit(), ft_atoi(), ft_strlen()
							//-> <stdlib.h> exit(), EXIT_SUCCESS, EXIT_FAILURE
							//-> <unistd.h> usleep(), write(), *_FILENO
# include <signal.h>      // kill(), SIGUSR1, SIGUSR2
# include <sys/types.h>   // pid_t

# ifndef WAIT_TIME
#  define WAIT_TIME 500000
# endif

# ifndef TIME_STEP
#  define TIME_STEP 500
# endif

typedef enum e_signal
{
	SIGNAL0 = SIGUSR1,
	SIGNAL1 = SIGUSR2,
	SIGNAL_SENDING = SIGUSR1,
	SIGNAL_FINISH = SIGUSR2,
}					t_sig;

typedef enum e_status
{
	WAITING,
	RECIEVED,
	FINISH,
}					t_status;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}					t_bool;

typedef struct s_message
{
	sig_atomic_t	confirm;
	sig_atomic_t	used;

}					t_message;

t_bool				ft_ispid(char *num);
void				exit_message(int status, char *message);
// void				advanced_pause(void);
void				kill_with_check(pid_t pid, int signal, int status);

#endif // CLIENT_H
