/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 13:52:02 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/06 14:25:15 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	x;

	x = 0;
	if (src == 0 && dest == 0)
		return (dest);
	while (x < n)
	{
		*((unsigned char*)dest + x) = *((unsigned char*)src + x);
		x++;
	}
	return (dest);
}
