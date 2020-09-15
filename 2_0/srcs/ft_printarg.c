/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 11:06:33 by julboyer          #+#    #+#             */
/*   Updated: 2020/09/09 14:52:38 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printarg(t_flags flags, va_list params, int res)
{
	if (flags.conv == 'c' || flags.conv == '%')
		res += ft_chandle(flags, params);
	else if (flags.conv == 'u' || flags.conv == 'x'
	|| flags.conv == 'X' || flags.conv == 'o')
		res += ft_xhandle(flags, params);
	else if (flags.conv == 'd' || flags.conv == 'i')
		res += ft_dhandle(flags, params);
	else if (flags.conv == 'p')
		res += ft_phandle(flags, params);
	else if (flags.conv == 'n')
		ft_nhandle(flags, params, res);
	else if (flags.conv == 's')
		res += ft_shandle(flags, params);
	else if (flags.conv == 'f' || flags.conv == 'e' || flags.conv == 'E')
		res += ft_fhandle(flags, params);
	else if (flags.conv == 'g' || flags.conv == 'G')
		res += ft_ghandle(flags, params);
	return (res);
}
