/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:56:37 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/13 09:16:09 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atoll(const char *str)
{
	int				sign;
	long long int	val;
	int				x;

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
	return (val * sign);
}
