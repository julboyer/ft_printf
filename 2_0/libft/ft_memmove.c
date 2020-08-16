/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:54:59 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 13:03:04 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libftprintf.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			x;
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = dest;
	psrc = (void*)src;
	x = 0;
	if ((src == 0 && dest == 0) || n == 0)
		return (dest);
	if (dest > src)
		while ((x + 1) <= n)
		{
			pdst[n - (x + 1)] = psrc[n - (x + 1)];
			x++;
		}
	else
	{
		while (x < n)
		{
			pdst[x] = psrc[x];
			x++;
		}
	}
	return (dest);
}
