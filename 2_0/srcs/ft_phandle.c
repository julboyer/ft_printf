/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:02:44 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/18 10:05:20 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_phandle(t_flags flags, va_list params)
{
	int		len;
	int		i;
	int		nbrlen;
	char	*res;
	char	*tmp;

	flags.u.lli = (unsigned long)va_arg(params, void*);
	nbrlen = ft_unbrlen_base(flags.u.lli, 16);
	i = (nbrlen > flags.prec) ? nbrlen : flags.prec;
	len = ((i + 2) > flags.width) ? (i + 2) : flags.width;
	flags.s_conv = i;
	flags.total_len = len;
	res = malloc(sizeof(*res) * len + 1);
	tmp = ft_ulltoa_basep(flags.u.lli, "0123456789abcdef", i, 16);
	res = ft_strcpy(res, tmp);
	free(tmp);
	res = ft_sharp_flag(res, flags);
	flags.s_conv += 2;
	if (len == flags.width)
		res = ft_width(res, flags);
	write(1, res, len);
	return (len);
}
