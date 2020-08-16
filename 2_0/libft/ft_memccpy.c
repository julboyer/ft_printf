/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:31:05 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/16 15:57:12 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	x;

	x = 0;
	if (src == 0 && dest == 0)
		return (dest);
	while (x < n && (*((unsigned char*)src + x) != (unsigned char)c))
	{
		*((unsigned char*)dest + x) = *((unsigned char*)src + x);
		x++;
	}
	if (*((unsigned char*)src + x) == (unsigned char)c)
	{
		*((unsigned char*)dest + x) = *((unsigned char*)src + x);
		x++;
		return (dest + x);
	}
	return (NULL);
}
