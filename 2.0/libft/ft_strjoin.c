/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:38:56 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/30 11:23:05 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	x;
	size_t	y;
	size_t	ss1;
	size_t	ss2;

	x = 0;
	y = 0;
	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	if (!(res = malloc(sizeof(*res) * (ss1 + ss2 + 1))))
		return (NULL);
	while (x < ss1)
	{
		res[x] = s1[x];
		x++;
	}
	while (y < ss2)
	{
		res[x + y] = s2[y];
		y++;
	}
	res[x + y] = '\0';
	return (res);
}
