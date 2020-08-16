/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:42:29 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/13 14:01:00 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_zero_flag(char *src, int len)
{
	char	*res;
	int		size_src;

	size_src = ft_strlen(src);
	if (size_src < len)
	{
		res = malloc(len + 1);
		ft_memset(res, '0', len - size_src);
		res[len - size_src] = '\0';
		ft_strcat(res, src);
		free(src);
		return (res);
	}
	return (src);
}
