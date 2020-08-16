/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:08:42 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/17 14:25:03 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *res;
	t_list *tmp;

	if (!(res = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	tmp = res;
	while (lst)
	{
		if (!(tmp->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (res);
}
