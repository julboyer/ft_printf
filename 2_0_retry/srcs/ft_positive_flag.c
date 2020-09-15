/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positive_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 09:57:45 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/29 14:25:25 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_positive_flag(char *s, t_flags *flags)
{
	ft_memmove(s + 1, s, flags->s_conv++);
	if (flags->u.lli < 0 || flags->u.d < 0)
		s[0] = '-';
	else if (flags->pref == '+')
		s[0] = '+';
	else
		s[0] = ' ';
	return (s);
}
