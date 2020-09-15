/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nhandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:35:49 by julboyer          #+#    #+#             */
/*   Updated: 2020/09/09 09:00:37 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_nhandle(t_flags flags, va_list params, int res)
{
	if (flags.type == 2)
	{
		if ((flags.u.lln = va_arg(params, long long int*)) != 0)
			*flags.u.lln = res;
	}
	else if (flags.type == 1)
	{
		if ((flags.u.ln = va_arg(params, long int*)) != 0)
			*flags.u.ln = res;
	}
	else if (flags.type == -1)
	{
		if ((flags.u.sn = va_arg(params, short int*)) != 0)
			*flags.u.sn = res;
	}
	else if (flags.type == -2)
	{
		if ((flags.u.s = va_arg(params, char*)) != 0)
			*flags.u.s = res;
	}
	else
	{
		if ((flags.u.n = va_arg(params, int*)) != 0)
			*flags.u.n = res;
	}
}
