/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_absp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:51:49 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/19 09:46:23 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libftprintf.h"
#include <stdio.h>

char				*ft_lltoa_absp(long long int n, int i)
{
	char		*res;

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
		while (i >= 0)
			res[i--] = '0';
	return (res);
}
