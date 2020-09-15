/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:56:05 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/26 13:58:00 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int x;

	x = 0;
	while ((unsigned char)s1[x] == (unsigned char)s2[x]
	&& (unsigned char)s1[x] && (unsigned char)s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
