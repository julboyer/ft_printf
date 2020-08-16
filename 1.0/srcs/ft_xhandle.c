/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xhandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:17:34 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/14 14:50:45 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_init_res(t_flags *flags, va_list params)
{
	char	*res;
	char	*base;

	base = NULL;
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
	if (flags->convert == 'u')
		base = ft_strdup("0123456789");
	else if (flags->convert == 'x')
		base = ft_strdup("0123456789abcdef");
	else if (flags->convert == 'X')
		base = ft_strdup("0123456789ABCDEF");
	else if (flags->convert == 'o')
		base = ft_strdup("01234567");
	res = ft_ulltoa_base(flags->u.ulli, base);
	free(base);
	return (res);
}

int		ft_xhandle(t_flags flags, va_list params)
{
	int		i;
	char	*res_s;

	i = 0;
	res_s = ft_init_res(&flags, params);
	res_s = ft_dot_flag(res_s, flags.prec, flags);
	if (flags.flag_width == '0')
		res_s = ft_zero_flag(res_s, flags.width);
	if (flags.convert != 'u' && flags.pref == '#')
		res_s = ft_diese_flag(res_s, flags);
	if (flags.flag_width != '0')
		res_s = ft_width(res_s, flags.width, flags);
	while (res_s[i])
		ft_putchar_fd(res_s[i++], 1);
	free(res_s);
	return (i);
}
