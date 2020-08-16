/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:52:23 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/14 14:51:14 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

int		ft_d_handle(t_flags flags, va_list params)
{
	int		i;
	char	*res_s;

	i = 0;
	if (flags.type == 2)
		flags.u.lli = va_arg(params, long long int);
	else if (flags.type == 1)
		flags.u.lli = va_arg(params, long int);
	else if (flags.type == -1)
		flags.u.lli = (short)va_arg(params, int);
	else if (flags.type == -2)
		flags.u.lli = (char)va_arg(params, int);
	else
		flags.u.lli = va_arg(params, int);
	res_s = ft_lltoa_abs(flags.u.lli);
	res_s = ft_dot_flag(res_s, flags.prec, flags);
	if (flags.flag_width == '0')
		res_s = ft_zero_flag(res_s, flags.width);
	res_s = ft_positive_flag(res_s, flags, flags.u.lli);
	if (flags.flag_width != '0')
		res_s = ft_width(res_s, flags.width, flags);
	while (res_s[i])
		ft_putchar_fd(res_s[i++], 1);
	free(res_s);
	return (i);
}
