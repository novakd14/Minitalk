/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:10:00 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/01 12:33:40 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define _POSIX_C_SOURCE 199309L

# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_message
{
	int		size;
	char	*message;
	int		bite;
	t_bool	recieving;
}			t_message;

#endif // SERVER_H
