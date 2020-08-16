/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 18:58:17 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/14 10:25:41 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *res;
	t_list *tmp;

	res = *lst;
	while (res)
	{
		tmp = res;
		res = res->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
