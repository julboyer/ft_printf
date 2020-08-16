/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 10:06:31 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/30 11:24:10 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int x;

	x = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[x] == (unsigned char)s2[x]
	&& (unsigned char)s1[x] && (unsigned char)s2[x] && x < (n - 1))
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
