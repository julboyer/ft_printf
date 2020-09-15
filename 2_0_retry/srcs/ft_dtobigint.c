/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtobigint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:34:23 by julboyer          #+#    #+#             */
/*   Updated: 2020/09/03 14:46:15 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_dtobigint(t_bigint *res, t_double flt)
{
	t_bigint	mantis;
	t_bigint	big2;
	int			i;

	i = 0;
	ft_lltobigint(flt.mantis, &mantis);
	ft_lltobigint(2, &big2);
	if (flt.exp < 0)
		while (i > flt.exp)
		{
			if ((mantis.nbr[0] & 1) == 1)
				ft_bigint_pow10(1, &mantis);
			ft_divbigint(&mantis, &big2, res);
			mantis = *res;
			i--;
		}
	else
		while (i < flt.exp)
		{
			ft_multbigint(&mantis, &big2, res);
			mantis = *res;
			i++;
		}
}
