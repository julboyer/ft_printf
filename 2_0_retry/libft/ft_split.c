/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 18:17:16 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 13:03:36 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static int		ft_wordcount(char const *s, char c)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			x++;
		}
		if (s[i])
			i++;
	}
	return (x);
}

static int		ft_wordlen(char const *s, char c)
{
	int x;

	x = 0;
	while (s[x] && s[x] != c)
		x++;
	return (x);
}

static char		**ft_free(char **s, int x)
{
	int i;

	i = 0;
	while (i < x)
		free(s[i++]);
	free(s);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		x;

	if (!(res = malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	x = 0;
	i = 0;
	while (s[i] && x < ft_wordcount(s, c))
	{
		if (s[i] != c)
		{
			if (!(res[x] = malloc(sizeof(char) * (ft_wordlen(&s[i], c) + 1))))
				return (ft_free(res, x));
			j = 0;
			while (s[i] && s[i] != c)
				res[x][j++] = s[i++];
			res[x++][j] = '\0';
		}
		if (s[i])
			i++;
	}
	res[x] = NULL;
	return (res);
}
