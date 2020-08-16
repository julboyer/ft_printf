/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:04:33 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 14:50:28 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	tmp = ft_calloc(sizeof(*tmp) * len, sizeof(*tmp) * len);
	tmp = ft_strncpy(tmp, res_s, i);
	free(res_s);
	tmp = ft_width(tmp, flags);
	write(1, tmp, len);
	free(tmp);
	return (len);
}
