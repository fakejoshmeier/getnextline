/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 13:57:43 by jmeier            #+#    #+#             */
/*   Updated: 2017/10/11 21:46:35 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# define BUF_SIZE 4096

static int		search(char *line, int r, char c)
{
	int		i;

	i = 0;
	if (c == '0')
	{
		while ((i + 2 < r) && (line[i] != c) && (line[i + 1] != c) &&
			(line[i + 2] != c))
			i++;
	}
	else
	{
		while ((i < r) && (line[i] != c))
			i++;
	}
	return (i);
}

static char	*affix(char *line, char *buf, int i)
{
	char	*read_buf;
	int		j;

	j = 0;
	read_buf = ft_strnew(i - 1);
	while (j++ < i)
		read_buf[j] = buf[j];
	free(buf);
	line = ft_strjoin(line, read_buf);
	free(read_buf);
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	char	*init_buf;
	int		r;
	int		i;

	init_buf = ft_strnew(BUF_SIZE);
	r = read(fd, init_buf, BUF_SIZE);
	if (r < 0)
		return (-1);
	r = 0;
	if (!ft_strchr(init_buf, '\n'))
	{
		i = search(init_buf, r, '0');
		affix(*line, init_buf, i);
		return (0);
	}
	i = search(init_buf, r, '\n');
	affix(*line, init_buf, i);
	return (1);
}
