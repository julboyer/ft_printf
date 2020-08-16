/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diese_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:54:54 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/15 12:12:10 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include "../headers/ft_printf.h"

char	*ft_diese_flag_hexa(char *s, char type, int zero, int s_len)
{
	char *res;

	res = NULL;
	if (type == 'x' || type == 'p')
	{
		res = malloc(sizeof(*res) * (s_len + 3));
		res = ft_strcpy(res, "0x");
		if (zero >= 2)
			res = ft_strcat(res, (s + 2));
		else
			res = ft_strcat(res, (zero == 1) ? (s + 1) : s);
	}
	else if (type == 'X')
	{
		res = malloc(sizeof(*res) * (s_len + 3));
		res = ft_strcpy(res, "0X");
		if (zero >= 2)
			res = ft_strcat(res, (s + 2));
		else
			res = ft_strcat(res, (zero == 1) ? (s + 1) : s);
	}
	return (res);
}

char	*ft_diese_flag(char *s, t_flags flg)
{
	char	*res;
	int		s_len;
	int		zero;

	s_len = ft_strlen(s);
	zero = 0;
	res = NULL;
	if ((flg.prec < 0 && flg.convert != 'p') || flg.convert == 'o')
		while (s[zero] == '0')
			zero++;
	if (flg.u.ulli || flg.convert == 'p')
	{
		if (flg.convert == 'o')
		{
			res = malloc(sizeof(*res) * (s_len + 2));
			res[0] = '0';
			res[1] = 0;
			res = ft_strcat(res, zero > 0 ? (s + 1) : s);
		}
		else if (flg.convert == 'x' || flg.convert == 'X' || flg.convert == 'p')
			res = ft_diese_flag_hexa(s, flg.convert, zero, s_len);
		return (res);
	}
	return (s);
}
