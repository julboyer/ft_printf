/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:28:23 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/30 11:26:58 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t x;
	size_t y;
	size_t slittle;

	x = 0;
	slittle = ft_strlen(little);
	if (slittle == 0)
		return ((char*)big);
	while (big[x] && x < len)
	{
		y = 0;
		while (little[y] && ((x + y) < len))
		{
			if (little[y] == big[x + y])
				y++;
			else
				break ;
		}
		if (y == slittle)
			return ((char*)&big[x]);
		x++;
	}
	return (NULL);
}
