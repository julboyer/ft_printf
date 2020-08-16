/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:02:09 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/28 17:56:26 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	x;
	unsigned int	size;
	size_t			ssize;

	x = 0;
	ssize = ft_strlen(s);
	size = (start + len) > ssize ? (ssize - start) : len;
	if (start < ssize)
	{
		if (!(res = malloc(sizeof(char) * (size + 1))))
			return (0);
		while (x < size)
		{
			res[x] = s[start + x];
			x++;
		}
		res[x] = 0;
	}
	else
	{
		res = malloc(1);
		res[0] = 0;
	}
	return (res);
}
