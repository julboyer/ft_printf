/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:47 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 14:52:40 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_width(char *s, t_flags flags)
{
	if (flags.flag_width == '-')
		ft_memset(s + flags.conv_len, ' ', flags.width - flags.conv_len);
	else
	{
		ft_memmove(s + (flags.width - flags.conv_len), s, flags.conv_len);
		ft_memset(s + (flags.width - flags.conv_len), flags.flag_width,
		flags.width - flags.conv_len);
	}
	return (s);
}
