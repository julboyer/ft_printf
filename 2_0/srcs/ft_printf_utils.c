/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 10:45:51 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/17 14:05:54 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_lstrlen(const wchar_t *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

wchar_t		*ft_lstrncpy(wchar_t *dest, wchar_t *src, unsigned int n)
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
		dest[x] = L'\0';
		x++;
	}
	return (dest);
}

size_t		ft_unbrlen_base(unsigned long long n, unsigned int base_len)
{
	size_t x;

	x = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base_len;
		x++;
	}
	return (x);
}
