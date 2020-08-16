/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:41:02 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 13:01:22 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *res;

	if (!(res = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(res, (nmemb * size));
	return (res);
}
