/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:04:33 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/18 14:40:12 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_lshandle(t_flags flags, va_list params)
{
	wchar_t	*res_s;
	wchar_t	*tmp;
	int		i;
	int		len;

	tmp = va_arg(params, wchar_t*);
	res_s = tmp ? tmp : L"(null)";
	i = ft_lstrlen(res_s);
	i = (flags.prec > -1 && flags.prec < i) ? flags.prec : i;
	len = (i > flags.width) ? i : flags.width;
	flags.s_conv = i;
	flags.total_len = len;
	tmp = malloc(sizeof(*tmp) * len);
	tmp = ft_lstrncpy(tmp, res_s, i);
	if (len == flags.width)
		tmp = ft_lwidth(tmp, flags);
	i = 0;
	while (i < len)
		write(1, &tmp[i++], 1);
	free(tmp);
	return (len);
}

int		ft_shandle(t_flags flags, va_list params)
{
	char	*res_s;
	char	*tmp;
	int		i;
	int		len;

	if (flags.type == 1)
		return (ft_lshandle(flags, params));
	tmp = va_arg(params, char*);
	res_s = tmp ? tmp : "(null)";
	i = ft_strlen(res_s);
	i = (flags.prec > -1 && flags.prec < i) ? flags.prec : i;
	len = (i > flags.width) ? i : flags.width;
	flags.s_conv = i;
	flags.total_len = len;
	tmp = malloc(sizeof(*tmp) * len);
	tmp = ft_strncpy(tmp, res_s, i);
	if (len == flags.width)
		tmp = ft_width(tmp, flags);
	write(1, tmp, len);
	free(tmp);
	return (len);
}
