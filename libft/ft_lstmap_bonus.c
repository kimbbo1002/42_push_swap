/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:31:02 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 09:42:04 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_lstmap iterates through the list, applies the function f 
to each node's content, and creates a new list resulting of the successive 
applications of the function f

return value :
- the new list
- NULL if the allocation fails
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_content;
	void	*content;

	if (!lst)
		return (0);
	new_list = 0;
	while (lst)
	{
		content = f(lst->content);
		new_content = ft_lstnew(content);
		if (!new_content)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, new_content);
		lst = lst->next;
	}
	return (new_list);
}
