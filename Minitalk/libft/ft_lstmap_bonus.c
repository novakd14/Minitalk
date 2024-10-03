/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:50:26 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 21:29:01 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checknew(t_list *new, t_list *new_list,
	void (*del)(void *), void *new_content)
{
	if (new == NULL)
	{
		del(new_content);
		ft_lstclear(&new_list, del);
		return (0);
	}
	return (1);
}

// Iterates the list ’lst’ and applies the function ’f’ on the content of each
// node. Creates a new list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to delete the content of a node
// if needed.
// RETURN VALUE: The new list. NULL if the allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*orig;
	t_list	*new;
	void	*new_content;

	if (lst == NULL)
		return (NULL);
	new_list = NULL;
	orig = lst;
	while (orig->next != NULL)
	{
		new_content = f(orig->content);
		new = ft_lstnew(new_content);
		if (ft_checknew(new, new_list, del, new_content) == 0)
			return (NULL);
		ft_lstadd_back(&new_list, new);
		orig = orig->next;
	}
	new_content = f(orig->content);
	new = ft_lstnew(new_content);
	if (ft_checknew(new, new_list, del, new_content) == 0)
		return (NULL);
	ft_lstadd_back(&new_list, new);
	return (new_list);
}
