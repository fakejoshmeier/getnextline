/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 13:57:43 by jmeier            #+#    #+#             */
/*   Updated: 2017/10/05 23:07:07 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		a_function_to_look_through_whatever_has_been_added_to_the_buffer, specifically for 0s and newline characrters(char *line, int size)
{
	if (!ft_strchr(line, '\n'))
		return (0);
	










char	*read_input(const int fd)
{
	char	*init_buf;
	char	*read_buf;
	int		b;
	int		r;
	int		l;

	init_buf = ft_strnew(BUF_SIZE);
	b = 0;
	while ((r = read(fd, init_buf + b, BUF_SIZE - b)) > 0)
		b += r;
	l = 0;
	while (l < r && ((init_buf[l] != '\n') || (init_buf[l] != '0')))
		l++;
	ft_strncpy(read_buf, init_buf, l);
	free(init_buf);
	return (read_buf);
}

I need to find a way to stuff the line i've found into the **line parameter
To this end, read_input shall now just find the crap I need to read, stuff that output into a separate buffer.  After that buffer has been 


int		get_next_line(const int fd, char **line)
{
	int		i;

	*line = read_input(fd);
	if (ft_strlen(*line) == BUF_SIZE)
		return (1);
	if (ft_strlen(*line) > BUF_SIZE)
		return (0);
	return (-1);
}

int		main()
{
	char *line;

	while (get_next_line(1, &line))
	{
		;
	}
}
