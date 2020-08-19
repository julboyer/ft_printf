/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:47 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/19 10:48:18 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_lwidth(wchar_t *s, t_flags flags)
{
	if (flags.flag_width == '-')
		ft_memset(s + flags.s_conv, ' ',
		sizeof(*s) * (flags.width - flags.s_conv));
	else
	{
		ft_memmove(s + (flags.width - flags.s_conv), s,
		sizeof(*s) * flags.s_conv);
		ft_memset(s, flags.flag_width,
		sizeof(*s) * (flags.width - flags.s_conv));
	}
	return (s);
}

char	*ft_width(char *s, t_flags flags)
{
	if (flags.flag_width == '-')
		ft_memset(s + flags.s_conv, ' ', flags.width - flags.s_conv);
	else
	{
		if (flags.pref == '#' && flags.flag_width == '0' && flags.conv != 'o')
		{
			ft_memmove(s + (flags.width - flags.s_conv) + 2, s + 2,
			flags.s_conv - 2);
			ft_memset(s + 2, flags.flag_width, flags.width - flags.s_conv);
		}
		else if (((flags.pref == '#' && flags.conv == 'o')
		|| (flags.pref == '+' || flags.pref == ' ') || flags.u.lli < 0)
		&& flags.flag_width == '0')
		{
			ft_memmove(s + (flags.width - flags.s_conv) + 1, s + 1,
			flags.s_conv - 1);
			ft_memset(s + 1, flags.flag_width, flags.width - flags.s_conv);
		}
		else
		{
			ft_memmove(s + (flags.width - flags.s_conv), s, flags.s_conv);
			ft_memset(s, flags.flag_width, flags.width - flags.s_conv);
		}
	}
	return (s);
}
