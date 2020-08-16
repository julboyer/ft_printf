/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nhandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:35:49 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 13:35:35 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_nhandle(t_flags flags, va_list params, int res)
{
	if (flags.type == 2)
	{
		flags.u.lln = va_arg(params, long long int*);
		*flags.u.lln = res;
	}
	else if (flags.type == 1)
	{
		flags.u.ln = va_arg(params, long int*);
		*flags.u.ln = res;
	}
	else if (flags.type == -1)
	{
		flags.u.sn = va_arg(params, short int*);
		*flags.u.sn = res;
	}
	else if (flags.type == -2)
	{
		flags.u.s = va_arg(params, char*);
		*flags.u.s = res;
	}
	else
	{
		flags.u.n = va_arg(params, int*);
		*flags.u.n = res;
	}
}
