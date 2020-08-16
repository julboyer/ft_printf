/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:47:16 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/30 11:23:37 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t y;
	size_t dsize;
	size_t ssize;

	dsize = ft_strlen(dst);
	ssize = ft_strlen(src);
	y = 0;
	if (dsize < (size) && (size != 0))
	{
		while (src[y] && (dsize + y) < (size - 1))
		{
			dst[dsize + y] = src[y];
			y++;
		}
		dst[dsize + y] = '\0';
		return (dsize + ssize);
	}
	else
		return (size + ssize);
}
