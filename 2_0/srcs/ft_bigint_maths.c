/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_maths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:40:33 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/29 10:28:33 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_addbigint(t_bigint *a, t_bigint *b, t_bigint *res)
{
	int i;
	int ret;

	ft_lltobigint(0LL, res);
	i = 0;
	ret = 0;
	res->lastdig = ((a->lastdig > b->lastdig) ? a->lastdig : b->lastdig) + 1;
	while (i <= res->lastdig)
	{
		res->nbr[i] = (ret + a->nbr[i] + b->nbr[i]) % 10;
		ret = (ret + a->nbr[i] + b->nbr[i]) / 10;
		i++;
	}
	ft_zero_adjust(res);
}

void	ft_subbigint(t_bigint *a, t_bigint *b, t_bigint *res)
{
	int i;
	int ret;

	ft_lltobigint(0LL, res);
	i = 0;
	ret = 0;
	res->lastdig = ((a->lastdig > b->lastdig) ? a->lastdig : b->lastdig) + 1;
	while (i < res->lastdig)
	{
		res->nbr[i] = (a->nbr[i] - b->nbr[i] - ret);
		if (res->nbr[i] < 0)
		{
			res->nbr[i] += 10;
			ret = 1;
		}
		i++;
	}
	res->sign = a->sign;
	ft_zero_adjust(res);
}

void	ft_multbigint(t_bigint *a, t_bigint *b, t_bigint *res)
{
	int			i;
	int			j;
	t_bigint	tmp;
	t_bigint	apow;

	i = 0;
	ft_lltobigint(0, res);
	apow = *a;
	while (i <= b->lastdig)
	{
		j = 0;
		while (j < b->nbr[i])
		{
			ft_addbigint(res, &apow, &tmp);
			j++;
			*res = tmp;
		}
		ft_bigint_pow10(1, &apow);
		i++;
	}
	ft_zero_adjust(res);
}

void	ft_divbigint(t_bigint *a, t_bigint *b, t_bigint *res)
{
	t_bigint	tmp;
	t_bigint	a_sub;
	int			i;

	ft_lltobigint(0, &tmp);
	ft_lltobigint(0, &a_sub);
	ft_lltobigint(0, res);
	i = a->lastdig;
	res->lastdig = i;
	while (i >= 0)
	{
		ft_bigint_pow10(1, &a_sub);
		a_sub.nbr[0] = a->nbr[i];
		res->nbr[i] = 0;
		while (ft_bigintcomp(&a_sub, b) >= 0)
		{
			res->nbr[i]++;
			ft_subbigint(&a_sub, b, &tmp);
			a_sub = tmp;
		}
		i--;
	}
	ft_zero_adjust(res);
}
