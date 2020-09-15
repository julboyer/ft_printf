/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:36:44 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/16 16:35:11 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		if (*((unsigned char*)s + x) == (unsigned char)c)
			return ((void*)(s + x));
		x++;
	}
	return (NULL);
}
