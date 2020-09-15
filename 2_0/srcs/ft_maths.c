/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:15:03 by julboyer          #+#    #+#             */
/*   Updated: 2020/09/09 10:29:59 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_ceil(double f)
{
	int res;

	if (f < 0)
		res = (int)f;
	else
		res = (int)(f + 1);
	return (res);
}

int			ft_floor(double f)
{
	int res;

	if (f > 0)
		res = (int)f;
	else
		res = (int)f - 1;
	return (res);
}

double		ft_pow(double nb, int p)
{
	if (p == 0)
		return (1);
	if (p < 0)
	{
		p *= -1;
		nb = 1 / nb;
	}
	if (p > 0)
	{
		if ((p & 1) == 1)
			return (nb * ft_pow(nb, p - 1));
		else
		{
			nb *= nb;
			return (ft_pow(nb, p / 2));
		}
	}
	return (0);
}

double		ft_fabs(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
