/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:30:38 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/07 09:30:38 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;
	t_list	*content;

	if (!lst || !f || !del)
		return (0);
	list = 0;
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (!temp || !content)
		{
			if (temp)
				ft_lstclear(&temp, del);
			if (content)
				del(content);
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, temp);
		lst = lst->next;
	}
	return (list);
}
