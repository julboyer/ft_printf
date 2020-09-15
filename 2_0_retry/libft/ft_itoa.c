/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:18:32 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 13:01:58 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static int			ft_intlen(int n)
{
	int i;
	int x;

	i = n;
	x = 0;
	if (i <= 0)
		x++;
	while (i > 0 || i < 0)
	{
		i = i / 10;
		x++;
	}
	return (x);
}

static void			ft_neg_itoa(char *res, int n, int i)
{
	long int j;

	j = n;
	j = j * -1;
	while (i > 0)
	{
		res[i--] = (j % 10) + 48;
		j = j / 10;
	}
	res[0] = '-';
}

char				*ft_itoa(int n)
{
	char		*res;
	int			i;

	i = ft_intlen(n);
	if (!(res = malloc(sizeof(*res) * (i + 1))))
		return (NULL);
	res[i--] = '\0';
	if (n > 0)
		while (i >= 0)
		{
			res[i--] = (n % 10) + 48;
			n = n / 10;
		}
	else if (n < 0)
		ft_neg_itoa(res, n, i);
	else
		res[0] = '0';
	return (res);
}
