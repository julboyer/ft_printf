/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:05:27 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 13:02:36 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *res;

	if (!lst)
		return (NULL);
	res = lst;
	while (res->next)
		res = res->next;
	return (res);
}
