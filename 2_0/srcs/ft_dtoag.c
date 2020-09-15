/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:07:26 by julboyer          #+#    #+#             */
/*   Updated: 2020/09/11 15:33:58 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_zero_remove(t_bigint *tmp, t_flags *flgs, t_double *flt)
{
	int i;

	i = 0;
	flt->len_entier = 1 + ((flt->log_10 > 0) ? flt->log_10 : 0);
	if (flgs->sharp == '\0' && flt->len_entier <= tmp->lastdig)
	{
		while (tmp->nbr[i] == 0 && i <= (tmp->lastdig - flt->len_entier))
			i++;
		flgs->s_conv -= i - 1;
		ft_bigint_pow10(-i, tmp);
	}
	if (flt->len_entier > flgs->prec)
	{
		flgs->conv = 'e';
		flt->len_entier = 1;
	}
}

void		ft_round_off(t_bigint *tmp, t_double *flt, t_flags *flgs)
{
	t_bigint	big1;
	t_bigint	res;
	t_bigint	hold;
	int			tmpdig;

	hold = *tmp;
	ft_lltobigint(1, &big1);
	ft_bigint_pow10(flgs->prec - tmp->lastdig - 1, tmp);
	tmpdig = tmp->lastdig;
	if (hold.nbr[hold.lastdig - flgs->prec] > 5
	|| (hold.nbr[hold.lastdig - flgs->prec] >= 5 && (hold.lastdig > flgs->prec))
	|| (hold.nbr[hold.lastdig - flgs->prec] == 5 && (tmp->nbr[0] & 1) == 1))
	{
		if (tmp->lastdig == 0 && tmp->nbr[0] == 0)
			flt->log_10++;
		ft_addbigint(tmp, &big1, &res);
		*tmp = res;
	}
	if (tmpdig < tmp->lastdig)
		flt->log_10++;
	if (tmpdig < tmp->lastdig && flgs->conv != 'e' && flgs->conv != 'E'
		&& flt->log_10 > -1)
		flgs->s_conv++;
}

t_bigint	ft_tmpinit(t_double *flt, t_flags *flgs)
{
	t_bigint	tmp;
	t_bigint	res;

	ft_dtobigint(&tmp, *flt);
	res = tmp;
	if (flgs->prec <= tmp.lastdig)
		ft_round_off(&res, flt, flgs);
	ft_zero_remove(&res, flgs, flt);
	if (res.lastdig < flgs->s_conv && flgs->sharp == '\0')
		flgs->s_conv = res.lastdig + 1;
	if (flt->log_10 < 0 && (flgs->conv != 'e' && flgs->conv != 'E'))
	{
		res.lastdig += (-flt->log_10);
		flgs->s_conv += (-flt->log_10);
	}
	if (flgs->s_conv > flt->len_entier || flgs->sharp == '#')
		flgs->s_conv++;
	flgs->total_len = (flgs->pref == '+' || flgs->pref == ' '
					|| flt->sign == 1) ? flgs->s_conv + 1 : flgs->s_conv;
	if (flgs->conv == 'e' || flgs->conv == 'E')
		flt->len_e = 2 + ((flt->log_10 > 99 || flt->log_10 < -99) ? 3 : 2);
	flgs->total_len += flt->len_e;
	flgs->total_len = (flgs->total_len > flgs->width) ?
						flgs->total_len : flgs->width;
	return (res);
}

void		ft_write_e(char *res, int i, t_double flt, t_flags *flgs)
{
	res[i++] = flgs->conv;
	res[i++] = flt.log_10 >= 0 ? '+' : '-';
	flt.log_10 *= (flt.log_10 < 0) ? -1 : 1;
	flgs->s_conv += flt.len_e;
	flt.len_e -= 2;
	while (flt.len_e > 0)
	{
		res[i + --flt.len_e] = flt.log_10 % 10 + '0';
		flt.log_10 /= 10;
	}
}

char		*ft_dtoag(t_double flt, t_flags *flgs)
{
	int			i;
	t_bigint	tmp;
	char		*res;

	i = -1;
	tmp = ft_tmpinit(&flt, flgs);
	if (!(res = malloc(sizeof(*res) * flgs->total_len)))
		return (NULL);
	while (++i < flt.len_entier)
		res[i] = tmp.nbr[tmp.lastdig - i] + '0';
	if (flgs->s_conv > flt.len_entier || flgs->sharp == '#')
		res[i++] = '.';
	while ((i - 1) <= tmp.lastdig && i < flgs->s_conv)
	{
		res[i] = tmp.nbr[tmp.lastdig - (i - 1)] + '0';
		i++;
	}
	while (i < flgs->s_conv)
		res[i++] = '0';
	if (flgs->conv == 'e' || flgs->conv == 'E')
		ft_write_e(res, i, flt, flgs);
	return (res);
}
