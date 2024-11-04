/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:08:14 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/21 15:45:04 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buf	*ft_bufnew(int fd)
{
	t_buf	*new_node;

	new_node = (t_buf *)malloc(sizeof(t_buf));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->buf = NULL;
	new_node->size = 0;
	new_node->end_char = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_bufdel(t_buf **list, int fd)
{
	t_buf	*del_node;
	t_buf	*prev_node;

	del_node = *list;
	while (del_node != NULL && del_node->fd != fd)
	{
		prev_node = del_node;
		del_node = del_node->next;
	}
	if (del_node == *list)
		*list = del_node->next;
	else
		prev_node->next = del_node->next;
	if (del_node->buf != NULL)
		free(del_node->buf);
	free(del_node);
}
