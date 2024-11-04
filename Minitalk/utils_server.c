/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:54 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/04 18:49:57 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

extern t_message	g_mess;

void	exit_message(int status, char *message)
{
	size_t	len;

	len = ft_strlen(message);
	if (status == EXIT_SUCCESS)
		write(STDOUT_FILENO, message, len);
	else
		write(STDERR_FILENO, message, len);
	exit(status);
}

static void	init_message(int *byte_num, int *size_byte, char **message)
{
	if (*byte_num != (int)((g_mess.bit_num / 8) % 2))
	{
		g_mess.size <<= 8;
		g_mess.size += (size_t)g_mess.bytes[*byte_num];
		*byte_num = (*byte_num + 1) % 2;
		(*size_byte)++;
	}
	if (*size_byte > g_mess.size_prop)
	{
		g_mess.status = MESSAGE;
		*message = (char *)ft_calloc(g_mess.size + 1, sizeof(char));
		if (*message == NULL)
			exit_message(EXIT_FAILURE, "ERROR: Could not allocate memory.\n");
	}
}

static void	read_message(int *byte_num, char *message, size_t *mess_byte)
{
	if (*byte_num != (int)((g_mess.bit_num / 8) % 2))
	{
		message[*mess_byte] = g_mess.bytes[*byte_num];
		*byte_num = (*byte_num + 1) % 2;
		(*mess_byte)++;
		if (*mess_byte == g_mess.size)
		{
			ft_bzero(&g_mess, sizeof(g_mess));
			g_mess.size_prop = -1;
			ft_printf("%s\n", message);
			free(message);
		}
	}
}

void	recieve_message(void)
{
	int		size_byte;
	int		byte_num;
	size_t	mess_byte;
	char	*message;

	size_byte = 0;
	byte_num = 0;
	mess_byte = 0;
	message = NULL;
	while (TRUE)
	{
		if (g_mess.status == SIZE)
			init_message(&byte_num, &size_byte, &message);
		else if (g_mess.status == MESSAGE)
			read_message(&byte_num, message, &mess_byte);
		if (g_mess.status == WAITING)
			return ;
		if (sleep(2) == 0)
		{
			if (message != NULL)
				free(message);
			exit_message(EXIT_FAILURE, "ERROR: Stopped recieving message.\n");
		}
	}
}
