/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:06:39 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 13:05:48 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static int			ft_charcmp(char c, char const *set)
{
	unsigned int x;

	x = 0;
	while (x < ft_strlen(set))
	{
		if (c == set[x])
			return (1);
		x++;
	}
	return (0);
}

static unsigned int	ft_strstart(char const *s1, char const *set)
{
	unsigned int x;

	x = 0;
	while (s1[x] && ft_charcmp(s1[x], set))
		x++;
	if (s1[x])
		return (x);
	return (0);
}

static unsigned int	ft_strend(char const *s1, char const *set)
{
	unsigned int x;

	x = ft_strlen(s1);
	if (x == 0)
		return (0);
	x--;
	while (ft_charcmp(s1[x], set) && x > 0)
		x--;
	if (x > 0)
		return (x + 1);
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char			*res;
	unsigned int	len;
	unsigned int	x;
	unsigned int	start;

	if (!s1 || !set)
		return (NULL);
	start = ft_strstart(s1, set);
	len = ft_strend(s1, set) - start;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	x = 0;
	while (x < len)
	{
		res[x] = s1[start + x];
		x++;
	}
	res[x] = '\0';
	return (res);
}
