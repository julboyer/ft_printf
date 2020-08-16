/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:34:35 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/15 11:47:09 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_lshandle(t_flags flags, va_list params)
{
	wchar_t	*res_s;
	wchar_t *tmp;
	int		i;

	i = 0;
	tmp = va_arg(params, wchar_t*);
	res_s = ft_lstrdup(tmp ? tmp : L"(null)");
	if (flags.prec >= 0)
		res_s = ft_ldot_flag(res_s, flags.prec);
	res_s = ft_lwidth(res_s, flags.width, flags.flag_width);
	i = ft_putwstr(res_s);
	free(res_s);
	return (i);
}

int		ft_shandle(t_flags flags, va_list params)
{
	char	*res_s;
	int		i;
	char	*tmp;

	i = 0;
	res_s = NULL;
	tmp = NULL;
	if (flags.type == 1)
		return (ft_lshandle(flags, params));
	else
	{
		tmp = va_arg(params, char*);
		res_s = ft_strdup(tmp ? tmp : "(null)");
	}
	if (flags.prec >= 0)
		res_s = ft_dot_flag(res_s, flags.prec, flags);
	res_s = ft_width(res_s, flags.width, flags);
	while (res_s[i])
		ft_putchar_fd(res_s[i++], 1);
	free(res_s);
	return (i);
}
