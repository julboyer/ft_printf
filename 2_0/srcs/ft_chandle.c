/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 10:28:44 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/18 09:21:08 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_lchandle(t_flags flags, va_list params)
{
	int		len;
	int		i;
	wchar_t	*tmp;

	len = (flags.width < 1) ? 1 : flags.width;
	flags.s_conv = 1;
	flags.total_len = len;
	tmp = malloc(sizeof(*tmp) * len);
	if (flags.conv == 'c')
		tmp[0] = va_arg(params, wint_t);
	if (len == flags.width)
		tmp = ft_lwidth(tmp, flags);
	i = 0;
	while (i < len)
		write(1, &tmp[i++], 1);
	free(tmp);
	return (len);
}

int		ft_chandle(t_flags flags, va_list params)
{
	int		len;
	char	*tmp;

	if (flags.type == 1)
		return (ft_lchandle(flags, params));
	len = (flags.width < 1) ? 1 : flags.width;
	flags.s_conv = 1;
	flags.total_len = len;
	tmp = malloc(sizeof(*tmp) * len);
	if (flags.conv == 'c')
		tmp[0] = (char)va_arg(params, int);
	else
		tmp[0] = '%';
	if (len == flags.width)
		tmp = ft_width(tmp, flags);
	write(1, tmp, len);
	free(tmp);
	return (len);
}
