/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:10:00 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/06 12:43:37 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

// FOR: usleep()
# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif

// FOR: siginfo_t (and signals)
# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 199309L
# endif

# include "libft/libft.h" // ft_strlen(), ft_printf(), ft_calloc(), ft_bzero()
							//-> <stdlib.h> exit(), free(), EXIT_*
							//-> <unistd.h> get_pid(), write(), usleep(),
# include <signal.h>      // kill(), sigaction(), SIGUSR*
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

typedef enum e_bool
{
	FALSE,
	TRUE,
}					t_bool;

typedef enum e_status
{
	ERROR = -1,
	SUCCESS = 0,
}					t_status;

typedef struct s_message
{
	int				pid;
	char			bit;
	sig_atomic_t	recieved;
}					t_message;

void				init_signals(void);
t_status			kill_with_check(pid_t pid, int signal);
void				exit_message(int status, char *message);

#endif // SERVER_H
