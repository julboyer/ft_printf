/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:18:26 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/14 14:51:30 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_p_handle(t_flags flags, va_list params)
{
	int		i;
	char	*res_s;
	char	*base;

	i = 0;
	flags.u.lli = (unsigned long)va_arg(params, void*);
	base = ft_strdup("0123456789abcdef");
	res_s = ft_ulltoa_base(flags.u.lli, base);
	if (flags.prec == 0)
		res_s = ft_dot_flag(res_s, flags.prec, flags);
	res_s = ft_diese_flag(res_s, flags);
	res_s = ft_width(res_s, flags.width, flags);
	while (res_s[i])
		ft_putchar_fd(res_s[i++], 1);
	free(res_s);
	free(base);
	return (i);
}
