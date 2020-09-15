/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xhandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 10:48:45 by julboyer          #+#    #+#             */
/*   Updated: 2020/09/15 12:08:33 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_init_tmp(t_flags *flags, va_list params, int *i)
{
	char	*res;
	char	*base;
	int		base_len;

	if (flags->type == 2)
		flags->u.ulli = va_arg(params, unsigned long long int);
	else if (flags->type == 1)
		flags->u.ulli = va_arg(params, unsigned long int);
	else if (flags->type == -1)
		flags->u.ulli = (unsigned short)va_arg(params, unsigned int);
	else if (flags->type == -2)
		flags->u.ulli = (unsigned char)va_arg(params, unsigned int);
	else
		flags->u.ulli = va_arg(params, unsigned int);
	if (flags->conv == 'x' || flags->conv == 'X')
		base = flags->conv == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	else
		base = (flags->conv == 'u') ? "0123456789" : "01234567";
	base_len = ft_strlen(base);
	*i = (flags->prec == 0 && flags->u.lli == 0) ? 0 :
	ft_unbrlen_base(flags->u.ulli, base_len);
	*i = (*i > flags->prec) ? *i : flags->prec;
	res = ft_ulltoa_basep(flags->u.ulli, base, *i, base_len);
	return (res);
}

int		ft_xhandle(t_flags flags, va_list params)
{
	int		i;
	int		len;
	char	*res;
	char	*tmp;

	tmp = ft_init_tmp(&flags, params, &i);
	if (flags.pref == '#' && flags.u.ulli != 0)
		len = (flags.conv == 'x' || flags.conv == 'X`') ? i + 2 : i + 1;
	else
		len = i;
	len = (len > flags.width) ? len : flags.width;
	flags.s_conv = i;
	flags.total_len = len;
	res = malloc(sizeof(*res) * len + 1);
	res = ft_strcpy(res, tmp);
	free(tmp);
	if (flags.pref == '#')
		res = ft_sharp_flag(res, &flags);
	if (len == flags.width && flags.width != 0)
		res = ft_width(res, flags);
	write(1, res, len);
	free(res);
	return (len);
}
