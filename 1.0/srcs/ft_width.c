/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:09:44 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/15 12:02:23 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <wchar.h>

wchar_t		*ft_lstrcpy(wchar_t *dest, wchar_t *src)
{
	int x;

	x = 0;
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = L'\0';
	return (dest);
}

size_t		ft_lstrlen(const wchar_t *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

wchar_t		*ft_lstrcat(wchar_t *dest, wchar_t *src)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (dest[x] != L'\0')
		x++;
	while (src[y] != L'\0')
	{
		dest[x + y] = src[y];
		y++;
	}
	dest[x + y] = L'\0';
	return (dest);
}

char		*ft_width(char *src, unsigned int len, t_flags flag)
{
	char		*res;
	size_t		s_src;
	size_t		s_res;

	s_src = ft_strlen(src);
	s_res = len - ((flag.u.lli == 0 && flag.convert == 'c') ? ++s_src : s_src);
	res = NULL;
	if (s_src < len && flag.flag_width == '-')
	{
		res = malloc(sizeof(*res) * (len + 1));
		ft_strcpy(res, src);
		free(src);
		res[len] = '\0';
		ft_memset(res + s_src, ' ', s_res);
		return (res);
	}
	else if (s_src < len && (res = malloc(sizeof(*res) * (len + 1))))
	{
		ft_memset(res, ' ', s_res);
		res[s_res] = '\0';
		res = ft_strcat(res, src);
		free(src);
		return (res);
	}
	return (src);
}

wchar_t		*ft_lwidth(wchar_t *src, unsigned int len, char flag)
{
	wchar_t	*res;
	size_t	s_src;
	size_t	s_res;

	s_src = ft_lstrlen(src);
	s_res = len - s_src;
	res = NULL;
	if (s_src < len && flag == '-')
	{
		res = malloc(sizeof(*res) * (len + 1));
		ft_lstrcpy(res, src);
		free(src);
		res[len] = L'\0';
		ft_memset(res + s_src, L' ', sizeof(*res) * s_res);
		return (res);
	}
	else if (s_src < len && (res = malloc(sizeof(*res) * (len + 1))))
	{
		res[s_res] = 0;
		ft_memset(res, L' ', sizeof(*res) * s_res);
		res = ft_lstrcat(res, src);
		free(src);
		return (res);
	}
	return (src);
}
