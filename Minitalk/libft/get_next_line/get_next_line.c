/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:08:05 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/21 15:46:16 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_all(t_buf **list, char **line)
{
	t_buf	*curr_node;
	t_buf	*next_node;

	if (list != NULL && *list != NULL)
	{
		curr_node = *list;
		while (curr_node != NULL)
		{
			if (curr_node->buf != NULL)
				free(curr_node->buf);
			next_node = curr_node->next;
			free(curr_node);
			curr_node = next_node;
		}
		*list = NULL;
	}
	if (*line != NULL)
	{
		free(*line);
		*line = NULL;
	}
}

static t_buf	*check_fd(int fd, t_buf **list)
{
	t_buf	*curr_node;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	curr_node = *list;
	while (curr_node != NULL && curr_node->fd != fd && curr_node->next != NULL)
		curr_node = curr_node->next;
	if (curr_node == NULL || curr_node->fd != fd)
	{
		curr_node = ft_bufnew(fd);
		if (curr_node == NULL)
			return (NULL);
		curr_node->next = *list;
		*list = curr_node;
	}
	curr_node->size = 0;
	return (curr_node);
}

static int	save_buf(t_buf *node, char **line, size_t *len)
{
	char	*temp;

	node->end_char = (char *)ft_memchr(node->buf, '\n', node->size);
	if (node->end_char != NULL)
		node->size = node->end_char + 1 - node->buf;
	temp = (char *)malloc((*len + node->size + 1) * sizeof(char));
	if (temp == NULL)
		return (node->size = -2, -2);
	ft_memmove(temp, *line, *len);
	ft_memmove(temp + *len, node->buf, node->size);
	if (*line != NULL)
		free(*line);
	*line = temp;
	*(node->buf) = '\0';
	*len += node->size;
	*(*line + *len) = '\0';
	return (1);
}

static char	*read_line(int fd, t_buf *node, char **line, t_buf **list)
{
	size_t	len;

	len = 0;
	while (1)
	{
		if (node->size != 0)
		{
			if (save_buf(node, line, &len) == -2)
				return (free_all(list, line), NULL);
			if (node->end_char != NULL)
			{
				ft_memmove(node->buf, node->end_char + 1, BUFFER_SIZE
					- node->size);
				ft_bzero(node->buf + BUFFER_SIZE - node->size, node->size);
				return (*line);
			}
		}
		node->size = read(fd, node->buf, BUFFER_SIZE);
		if (node->size == -1)
			return (free_all(NULL, line), NULL);
		if (node->size == 0)
			return (*line);
		ft_bzero(node->buf + node->size, BUFFER_SIZE - node->size);
	}
}

// Returns a line read from a file descriptor (fd). Returns NULL if there is
// nothing else to read, or an error occurred.
char	*get_next_line(int fd)
{
	static t_buf	*list;
	t_buf			*node;
	char			*line;

	line = NULL;
	node = check_fd(fd, &list);
	if (node == NULL)
		return (free_all(&list, &line), NULL);
	if (node->buf == NULL)
	{
		node->buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (node->buf == NULL)
			return (free_all(&list, &line), NULL);
		ft_bzero(node->buf, BUFFER_SIZE);
	}
	else
	{
		while (node->size < BUFFER_SIZE && *(node->buf + node->size))
			node->size++;
	}
	if (read_line(fd, node, &line, &list) == NULL && node->size == -2)
		return (NULL);
	if ((*(node->buf) == '\0' && node->end_char != NULL) || node->size <= 0)
		ft_bufdel(&list, fd);
	return (line);
}
