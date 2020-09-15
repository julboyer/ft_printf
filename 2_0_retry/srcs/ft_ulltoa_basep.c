/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_basep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:22:05 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/18 14:29:53 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ulltoa_basep(unsigned long long n, char *base, int i, int base_len)
{
	char			*res;

	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i--] = '\0';
	if (n > 0)
	{
		while (n != 0)
		{
			res[i] = base[n % base_len];
			n = n / base_len;
			i--;
		}
		while (i >= 0)
			res[i--] = base[0];
	}
	else
		while (i >= 0)
			res[i--] = base[0];
	return (res);
}
