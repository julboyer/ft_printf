/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 09:48:36 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/30 10:10:02 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_chekval(long int val)
{
	if (val == LONG_MAX)
		return (-1);
	else if (val == LONG_MIN)
		return (0);
	else if (val > INT_MAX)
		return (0);
	else if (val < INT_MIN)
		return (-1);
	else
		return (val);
}

int			ft_atoi(const char *str)
{
	int			sign;
	long int	val;
	int			x;

	x = 0;
	val = 0;
	sign = 1;
	while ((str[x] > 8 && str[x] < 14) || (str[x] == ' '))
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sign = sign * -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		val = (val * 10) + (str[x] - 48);
		x++;
	}
	return (ft_chekval(val * sign));
}
