/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 10:54:08 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/03 15:46:03 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line2(int fd, char **tmp, char **sub)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;
	char	*tmp2;

	ret = 1;
	while (!(*sub = ft_strchr(tmp[fd], '\n')) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (ret);
		buf[ret] = '\0';
		if (tmp[fd] == NULL)
			tmp[fd] = ft_strdup(buf);
		else if (ret > 0)
		{
			tmp2 = tmp[fd];
			tmp[fd] = ft_strjoin(tmp2, buf);
			free(tmp2);
		}
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp[1024];
	char		*tmp2;
	int			ret;
	char		*sub;

	if (BUFFER_SIZE < 1 || fd < 0 || line == NULL)
		return (-1);
	ret = get_next_line2(fd, tmp, &sub);
	if (ret == -1)
		return (-1);
	if (sub == 0)
	{
		*line = tmp[fd];
		return (0);
	}
	else
	{
		*line = ft_substr(tmp[fd], 0, (sub - tmp[fd]));
		tmp2 = tmp[fd];
		tmp[fd] = ft_strdup(sub + 1);
		free(tmp2);
		return (1);
	}
}
