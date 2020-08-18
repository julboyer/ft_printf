/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:06:27 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/17 14:18:09 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libftprintf.h"

static unsigned int	ft_nbrlen(unsigned long long n, unsigned int base_len)
{
	int x;

	x = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base_len;
		x++;
	}
	return (x);
}

char				*ft_ulltoa_base(unsigned long long n, char *base)
{
	char			*res;
	unsigned int	i;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	i = ft_nbrlen(n, base_len);
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i--] = '\0';
	if (n > 0)
		while (n != 0)
		{
			res[i] = base[n % base_len];
			n = n / base_len;
			if (i > 0)
				i--;
			else
				break ;
		}
	else
		res[0] = base[0];
	return (res);
}
