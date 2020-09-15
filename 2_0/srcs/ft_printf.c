/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:07:47 by julboyer          #+#    #+#             */
/*   Updated: 2020/09/10 10:06:39 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libftprintf.h"

void	ft_verif_flags(t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->flag_width = '-';
		flags->width *= -1;
	}
	if (flags->prec >= 0 && flags->flag_width != '-' && (flags->conv != 'f'
		&& flags->conv != 'e' && flags->conv != 'E' && flags->conv != 'g'
		&& flags->conv != 'G'))
		flags->flag_width = ' ';
	if (flags->conv == 'p')
		flags->pref = '#';
	if (flags->conv == 'u')
		flags->pref = '\0';
	if (flags->prec < 0 && (flags->conv == 'f' || flags->conv == 'e'
			|| flags->conv == 'E' || flags->conv == 'g' || flags->conv == 'G'))
		flags->prec = 6;
	if (flags->prec == 0 && (flags->conv == 'g' || flags->conv == 'G'))
		flags->prec = 1;
	if (flags->pref == '#' && (flags->conv == 'f' || flags->conv == 'e'
			|| flags->conv == 'E' || flags->conv == 'g' || flags->conv == 'G'))
		flags->pref = '\0';
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
		flags->conv = s[i++];
	ft_verif_flags(flags);
	return (i);
}

int		ft_printf_parse(const char *s, va_list params, t_flags *flags, int i)
{
	while ((ft_isprintflag(s[i]) == 1))
	{
		if (s[i] == '0' || s[i] == '-')
			(flags->flag_width != '-') ? flags->flag_width = s[i++] : i++;
		else
			(flags->pref != '+' || flags->pref != ' ')
			? flags->pref = s[i++] : i++;
		if (s[i - 1] == '#')
			flags->sharp = '#';
	}
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

void	ft_reset_flags(t_flags *flags)
{
	flags->flag_width = ' ';
	flags->type = 0;
	flags->pref = '\0';
	flags->sharp = '\0';
	flags->prec = -1;
	flags->width = 0;
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
			ft_reset_flags(&parse);
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
