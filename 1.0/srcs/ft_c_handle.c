/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:45:12 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/14 16:40:50 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_lchandle(wint_t c, t_flags flags)
{
	wchar_t	*res_s;
	int		i;

	i = 0;
	if (!(res_s = malloc(sizeof(*res_s) * 2)))
		return (-1);
	res_s[0] = c;
	res_s[1] = L'\0';
	res_s = ft_lwidth(res_s, flags.width, flags.flag_width);
	while (res_s[i])
		ft_putwc(res_s[i++]);
	free(res_s);
	return (i);
}

int	ft_chandle(t_flags flags, va_list params)
{
	char	*res_s;
	int		i;

	i = 0;
	if (flags.convert == 'c')
	{
		if (flags.type == 1)
			return (ft_lchandle(va_arg(params, wint_t), flags));
		else
			flags.u.lli = (char)va_arg(params, int);
	}
	else
		flags.u.lli = '%';
	if (!(res_s = malloc(sizeof(*res_s) * 2)))
		return (-1);
	res_s[0] = flags.u.lli;
	res_s[1] = '\0';
	if (flags.convert == '%' && flags.flag_width == '0')
		res_s = ft_zero_flag(res_s, flags.width);
	else
		res_s = ft_width(res_s, flags.width, flags);
	i = ft_print(res_s, flags);
	free(res_s);
	return (i);
}
