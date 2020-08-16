/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:18:16 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/13 10:19:12 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

int	ft_printarg(t_flags flags, va_list params, int res)
{
	if (flags.convert == 'c' || flags.convert == '%')
		res += ft_chandle(flags, params);
	else if (flags.convert == 'u' || flags.convert == 'x'
	|| flags.convert == 'X' || flags.convert == 'o')
		res += ft_xhandle(flags, params);
	else if (flags.convert == 'd' || flags.convert == 'i')
		res += ft_d_handle(flags, params);
	else if (flags.convert == 'p')
		res += ft_p_handle(flags, params);
	else if (flags.convert == 'n')
		ft_nhandle(flags, params, res);
	else if (flags.convert == 's')
		res += ft_shandle(flags, params);
	return (res);
}
