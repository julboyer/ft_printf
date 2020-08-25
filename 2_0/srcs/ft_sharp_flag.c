/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharp_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:52:53 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/20 11:44:36 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_sharp_flag(char *s, t_flags *flags)
{
	if ((flags->conv == 'x' && flags->u.ulli != 0) || flags->conv == 'p')
	{
		ft_memmove((s + 2), s, flags->s_conv);
		s[0] = '0';
		s[1] = 'x';
		flags->s_conv += 2;
	}
	else if (flags->conv == 'X' && flags->u.ulli != 0)
	{
		ft_memmove(s + 2, s, flags->s_conv);
		s[0] = '0';
		s[1] = 'X';
		flags->s_conv += 2;
	}
	else if (flags->conv == 'o' && flags->u.ulli != 0)
	{
		ft_memmove(s + 1, s, flags->s_conv);
		s[0] = '0';
		flags->s_conv++;
	}
	return (s);
}
