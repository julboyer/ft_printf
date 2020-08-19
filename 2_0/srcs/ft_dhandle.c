/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dhandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 09:04:25 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/19 10:22:15 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_dhandle(t_flags flgs, va_list params)
{
	int		i;
	int		len;
	char	*res;
	char	*tmp;

	len = 0;
	if (flgs.type == 2)
		flgs.u.lli = va_arg(params, long long int);
	else if (flgs.type == 1)
		flgs.u.lli = va_arg(params, long int);
	else if (flgs.type == -1)
		flgs.u.lli = (short)va_arg(params, int);
	else if (flgs.type == -2)
		flgs.u.lli = (char)va_arg(params, int);
	else
		flgs.u.lli = va_arg(params, int);
	i = (flgs.prec == 0 && flgs.u.lli == 0) ? 0 : ft_nbrlen(flgs.u.lli);
	i = (i > flgs.prec) ? i : flgs.prec;
	len = (flgs.pref == '+' || flgs.pref == ' ' || flgs.u.lli < 0) ? i + 1 : i;
	len = (len > flgs.width) ? len : flgs.width;
	flgs.s_conv = i;
	flgs.total_len = len;
	tmp = ft_lltoa_absp(flgs.u.lli, i);
	res = malloc(sizeof(*res) * (len + 1));
	res = ft_strcpy(res, tmp);
	free(tmp);
	if (flgs.pref == '+' || flgs.pref == ' ' || flgs.u.lli < 0)
	{
		res = ft_positive_flag(res, flgs);
		flgs.s_conv++;
	}
	if (len == flgs.width && flgs.width != 0)
		res = ft_width(res, flgs);
	write(1, res, len);
	free(res);
	return (len);
}
