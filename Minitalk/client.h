/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:10:00 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/04 12:59:59 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif

# ifndef WAIT_TIME
#  define WAIT_TIME 300
# endif

# include "libft/libft.h" // ft_isdigit(), ft_atoi(), ft_strlen()
							//-> <stdlib.h> exit(), EXIT_SUCCESS, EXIT_FAILURE
							//-> <unistd.h> usleep(), write(), *_FILENO
# include <signal.h>      // kill(), SIGUSR1, SIGUSR2
# include <sys/types.h>   // pid_t

typedef enum e_signal
{
	SIGNAL0 = SIGUSR1,
	SIGNAL1 = SIGUSR2,
}		t_sig;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}		t_bool;

void	exit_message(int status, char *message);
void	kill_with_check(pid_t pid, int signal);

#endif // CLIENT_H
