/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:02:19 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/16 13:52:17 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t x;

	x = 0;
	if (n == 0)
		return (0);
	while (*((unsigned char*)s1 + x) == *((unsigned char*)s2 + x)
		&& x < (n - 1))
		x++;
	return (*((unsigned char*)s1 + x) - *((unsigned char*)s2 + x));
}
