/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_abs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:51:49 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/11 18:40:23 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include <stdio.h>

static int			ft_intlen(long long n)
{
	int x;

	x = 0;
	if (n == 0)
		return (1);
	while (n > 0 || n < 0)
	{
		n = n / 10;
		x++;
	}
	return (x);
}

char				*ft_lltoa_abs(long long int n)
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
		while (i >= 0)
		{
			res[i--] = ((n % 10) * -1) + 48;
			n = n / 10;
		}
	else
		res[0] = '0';
	return (res);
}
