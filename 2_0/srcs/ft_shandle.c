/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:04:33 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 12:27:17 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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
	tmp = ft_calloc(sizeof(*tmp) * len);
	tmp = ft_strncpy(tmp, res_s, i);
	
}