/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positive_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:58:04 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/13 10:15:10 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_positive_flag2(char *s, t_flags flags, int zero)
{
	char *res;

	if (flags.pref == '+')
	{
		res = malloc(sizeof(*res) * (ft_strlen(s) + 2));
		res = ft_strcpy(res, "+");
		res = ft_strcat(res, (zero) ? (s + 1) : s);
		free(s);
		return (res);
	}
	else if (flags.pref == ' ')
	{
		res = malloc(sizeof(*res) * (ft_strlen(s) + 2));
		res = ft_strcpy(res, " ");
		res = ft_strcat(res, (zero) ? (s + 1) : s);
		free(s);
		return (res);
	}
	return (s);
}

char	*ft_positive_flag(char *s, t_flags flags, long long int nbr)
{
	char	*res;
	int		zero;

	zero = 0;
	if (flags.prec < 0)
		while (s[zero] == '0')
			zero++;
	if (nbr >= 0)
		return (ft_positive_flag2(s, flags, zero));
	else
	{
		res = malloc(sizeof(*res) * (ft_strlen(s) + 2));
		res = ft_strcpy(res, "-");
		res = ft_strcat(res, (zero) ? (s + 1) : s);
		free(s);
		return (res);
	}
	return (s);
}
