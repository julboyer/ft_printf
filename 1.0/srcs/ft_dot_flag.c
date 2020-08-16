/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:22:04 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/14 12:21:49 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

wchar_t	*ft_lstrdup(wchar_t *s1)
{
	wchar_t	*dup;
	int		x;

	x = 0;
	if (!(dup = malloc(sizeof(*s1) * (ft_lstrlen(s1) + 1))))
		return (NULL);
	while (s1[x])
	{
		dup[x] = s1[x];
		x++;
	}
	dup[x] = L'\0';
	return (dup);
}

wchar_t	*ft_lstrncpy(wchar_t *dest, wchar_t *src, unsigned int n)
{
	unsigned int x;

	x = 0;
	while (src[x] && x < n)
	{
		dest[x] = src[x];
		x++;
	}
	while (x < n)
	{
		dest[x] = '\0';
		x++;
	}
	return (dest);
}

char	*ft_dot_flag(char *src, int i, t_flags flags)
{
	int		size_src;
	char	*res;

	size_src = ft_strlen(src);
	if (flags.convert == 's' || flags.u.lli == 0 || flags.u.ulli == 0)
	{
		if (size_src > i && flags.prec > -1)
		{
			res = malloc(sizeof(*res) * (i + 1));
			ft_strncpy(res, src, i);
			res[i] = '\0';
			free(src);
			return (res);
		}
	}
	if (size_src < i && flags.convert != 's')
	{
		res = malloc(sizeof(*res) * (i + 1));
		ft_memset(res, '0', i - size_src);
		res[i - size_src] = 0;
		res = ft_strcat(res, src);
		free(src);
		return (res);
	}
	return (src);
}

wchar_t	*ft_ldot_flag(wchar_t *src, int i)
{
	int		size_src;
	wchar_t	*res;

	size_src = ft_lstrlen(src);
	if (size_src > i)
	{
		res = malloc(sizeof(*res) * (i + 1));
		ft_lstrncpy(res, src, i);
		res[i] = L'\0';
		free(src);
		return (res);
	}
	return (src);
}
