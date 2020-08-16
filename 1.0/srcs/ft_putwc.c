/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:58:43 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/15 11:58:17 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_putwc(wint_t c)
{
	write(1, &c, 1);
}

int		ft_putwstr(wchar_t *s)
{
	int i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int		ft_print(char *s, t_flags flags)
{
	int i;

	i = 0;
	if (flags.u.lli == 0 && flags.flag_width == '-')
		ft_putchar_fd(s[i++], 1);
	while (s[i])
		ft_putchar_fd(s[i++], 1);
	if (flags.u.lli == 0 && flags.flag_width != '-')
		ft_putchar_fd(s[i++], 1);
	return (i);
}
