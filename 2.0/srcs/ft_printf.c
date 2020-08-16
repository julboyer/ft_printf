/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:07:47 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/15 12:56:28 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_verif_flags(t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->flag_width = '-';
		flags->width *= -1;
	}
	if (flags->prec >= 0 && flags->flag_width != '-')
		flags->flag_width = ' ';
}

int		ft_prec_parse(const char *s, va_list params, t_flags *flags, int i)
{
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
		{
			flags->prec = va_arg(params, int);
			i++;
		}
		else
		{
			flags->prec = ft_atoll(&s[i]);
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
	}
	while (s[i] == 'l' || s[i] == 'h')
		(s[i++] == 'l') ? flags->type++ : flags->type--;
	if (ft_isprintconvert(s[i]) == 1)
		flags->convert = s[i++];
	ft_verif_flags(flags);
	return (i);
}

int		ft_printf_parse(const char *s, va_list params, t_flags *flags, int i)
{
	flags->flag_width = ' ';
	flags->type = 0;
	flags->pref = '\0';
	flags->prec = -1;
	flags->width = 0;
	while ((ft_isprintflag(s[i]) == 1))
		if (s[i] == '0' || s[i] == '-')
			(flags->flag_width != '-') ? flags->flag_width = s[i++] : i++;
		else
			flags->pref = s[i++];
	if (s[i] == '*')
	{
		flags->width = va_arg(params, int);
		i++;
	}
	else if (s[i] >= '1' && s[i] <= '9')
	{
		flags->width = ft_atoll(&s[i++]);
		while (s[i] >= '0' && s[i] <= '9')
			i++;
	}
	i = ft_prec_parse(s, params, flags, i);
	return (i);
}

int		ft_printf(const char *s, ...)
{
	va_list	params;
	t_flags	parse;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(params, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i = ft_printf_parse(s, params, &parse, i + 1);
			res = ft_printarg(parse, params, res);
		}
		else
		{
			ft_putchar_fd(s[i++], 1);
			res++;
		}
	}
	va_end(params);
	return (res);
}
