/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 14:02:03 by julboyer          #+#    #+#             */
/*   Updated: 2020/05/12 18:15:13 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int lnb;

	lnb = n;
	if (lnb < 0)
	{
		write(fd, "-", 1);
		lnb *= -1;
	}
	if (lnb >= 0 && lnb < 10)
		ft_putchar_fd(lnb + 48, fd);
	if (lnb >= 10)
	{
		ft_putnbr_fd(lnb / 10, fd);
		ft_putnbr_fd(lnb % 10, fd);
	}
}
