/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:44:20 by julboyer          #+#    #+#             */
/*   Updated: 2020/09/10 14:22:44 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_double	ft_initfltg(double n)
{
	t_double			flt;
	unsigned long long	dtoll;
	double				*d;
	int					log_2;

	d = &n;
	log_2 = 52;
	dtoll = *(unsigned long long*)d;
	flt.exp = (9218868437227405312ULL & dtoll) >> 52;
	flt.mantis = ((MSKMANTIS) & dtoll) + ((flt.exp > 0) ? (1UL << 52) : 0);
	flt.exp = (flt.exp) ? flt.exp - 1075 : -1074;
	while (!(flt.mantis >> (log_2)) && log_2)
		log_2--;
	flt.sign = dtoll >> 63;
	flt.log_10 = ft_floor((log_2 + flt.exp) * (LOG10_2));
	if (flt.log_10 > -309)
	{
		if (ft_fabs(n * ft_pow(10, -flt.log_10)) < 1)
			flt.log_10--;
		else if (ft_fabs(n * ft_pow(10, -(flt.log_10 + 1))) >= 1)
			flt.log_10++;
	}
	flt.len_e = 0;
	return (flt);
}

char		*ft_check_infg(t_double flt, t_flags *flags, int *len)
{
	char *res;

	if (flt.sign == 1)
	{
		flags->s_conv = 4;
		*len = (flags->width > 4) ? flags->width : 4;
		if (!(res = malloc(sizeof(*res) * *len + 1)))
		{
			*len = -1;
			return (res);
		}
		res = ft_strcpy(res, "-inf");
	}
	else
	{
		flags->s_conv = 3;
		*len = (flags->width > 3) ? flags->width : 3;
		if (!(res = malloc(sizeof(*res) * *len + 1)))
		{
			*len = -1;
			return (res);
		}
		res = ft_strcpy(res, "inf");
	}
	return (res);
}

int			ft_check_nang(t_double flt, t_flags flags)
{
	int		len;
	char	*res;

	if (flags.flag_width == '0')
		flags.flag_width = ' ';
	if (flt.exp == 972)
	{
		if (flt.mantis == 1ULL << 52)
			res = ft_check_infg(flt, &flags, &len);
		else
		{
			flags.s_conv = 3;
			len = (flags.width > 3) ? flags.width : 3;
			res = malloc(sizeof(*res) * len + 1);
			res = ft_strcpy(res, "nan");
		}
		if (!res)
			return (-1);
		if (flags.width == len && flags.width != 0)
			ft_width(res, flags);
		write(1, res, len);
		free(res);
		return (len);
	}
	return (0);
}

int			ft_gprint(t_flags flgs, t_double flt)
{
	int			len;
	char		*res;

	if ((len = ft_check_nang(flt, flgs)) != 0)
		return (len);
	if (flgs.conv == 'e' || flgs.conv == 'E')
		flt.len_entier = 1;
	flgs.s_conv = flgs.prec;
	res = ft_dtoag(flt, &flgs);
	flgs.s_conv += flt.len_e;
	if (flt.sign == 1 || flgs.pref == ' ' || flgs.pref == '+')
		ft_positive_flag(res, &flgs);
	if (flgs.width == flgs.total_len && flgs.width != 0)
		ft_width(res, flgs);
	write(1, res, flgs.total_len);
	free(res);
	return (flgs.total_len);
}

int			ft_ghandle(t_flags flgs, va_list params)
{
	t_double	flt;

	flgs.u.d = va_arg(params, double);
	flt = ft_initfltg(flgs.u.d);
	flt.log_10 = (flgs.u.d == 0.0) ? 0 : flt.log_10;
	if (flt.log_10 < -4 || flt.len_entier > flgs.prec)
	{
		if (flgs.conv == 'g')
			flgs.conv = 'e';
		else if (flgs.conv == 'G')
			flgs.conv = 'E';
	}
	return (ft_gprint(flgs, flt));
}
