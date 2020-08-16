/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:06:21 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/30 11:27:13 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int x;

	x = 0;
	while (s[x])
		x++;
	while (x >= 0)
	{
		if (s[x] == c)
			return ((char*)&s[x]);
		x--;
	}
	return (NULL);
}
