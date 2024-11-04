/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:23:20 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 20:08:36 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts the number of nodes in a list.
// RETURN VALUE: Counts the number of nodes in a list.
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*next;

	next = lst;
	size = 0;
	while (next != NULL)
	{
		next = next->next;
		size++;
	}
	return (size);
}
