/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:02:44 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/19 11:30:55 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_phandle(t_flags flags, va_list params)
{
	int		len;
	int		i;
	char	*res;
	char	*tmp;

	flags.u.ulli = (unsigned long)va_arg(params, void*);
	i = (flags.prec == 0 && flags.u.ulli == 0) ? 0 :
	ft_unbrlen_base(flags.u.ulli, 16);
	i = (i > flags.prec) ? i : flags.prec;
	len = ((i + 2) > flags.width) ? (i + 2) : flags.width;
	flags.s_conv = i;
	flags.total_len = len;
	res = malloc(sizeof(*res) * len + 1);
	tmp = ft_ulltoa_basep(flags.u.ulli, "0123456789abcdef", i, 16);
	res = ft_strcpy(res, tmp);
	free(tmp);
	res = ft_sharp_flag(res, &flags);
	if (len == flags.width)
		res = ft_width(res, flags);
	write(1, res, len);
	free(res);
	return (len);
}
