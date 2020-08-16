/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:06:21 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 13:05:43 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
