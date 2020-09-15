/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:10:05 by julboyer          #+#    #+#             */
/*   Updated: 2020/09/11 13:28:00 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lltobigint(long long n, t_bigint *b)
{
	int i;

	b->sign = (n < 0) ? -1 : 1;
	n *= b->sign;
	b->lastdig = -1;
	i = 0;
	while (i < MAXDIGIT)
		b->nbr[i++] = 0;
	i = 0;
	if (n == 0)
		b->lastdig++;
	else
		while (n > 0)
		{
			b->nbr[i++] = (n % 10);
			n /= 10;
			b->lastdig++;
		}
}

int		ft_bigintcomp(t_bigint *a, t_bigint *b)
{
	int i;

	if (a->lastdig > b->lastdig)
		return (1);
	if (b->lastdig > a->lastdig)
		return (-1);
	i = a->lastdig;
	while (i > 0 && a->nbr[i] == b->nbr[i])
		i--;
	return (a->nbr[i] - b->nbr[i]);
}

void	ft_bigint_pow10(int pow, t_bigint *b)
{
	int i;

	i = b->lastdig;
	if (b->nbr[0] || i)
	{
		if (pow > 0)
		{
			while (i >= 0)
			{
				b->nbr[pow + i] = b->nbr[i];
				i--;
			}
			while (++i < pow)
				b->nbr[i] = 0;
		}
		else if ((b->lastdig + pow >= 0) && (i = -1) != 0)
		{
			while (++i <= b->lastdig)
				b->nbr[i] = b->nbr[i - pow];
			while (++i <= b->lastdig)
				b->nbr[i] = 0;
		}
		b->lastdig += pow;
	}
}

void	ft_zero_adjust(t_bigint *b)
{
	while (b->nbr[b->lastdig] == 0 && b->lastdig > 0)
		b->lastdig--;
}
