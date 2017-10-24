/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 13:57:43 by jmeier            #+#    #+#             */
/*   Updated: 2017/10/24 00:49:29 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		parse(t_block **block, char *line)
{
	int i;

	i = 0;
	while ((*block)->str[i] != '\n' && (*block)->str[i] != '\0')
		i++;
	if ((*block)->str[i] == '\n')
	{
		ASSERT(line = ft_strsub((*block)->str, 0, i));
		ASSERT((*block)->tmp = ft_strdup((*block)->str + i + 1));
		free((*block)->str);
		(*block)->str = (*block)->tmp;
	}
	else if (!(*block)->str[i])
	{
		if (i == 0)
			return (0);
		ASSERT(line = ft_strdup((*block)->str));
		free((*block)->str);
		(*block)->str = NULL;
	}
	return (1);
}

/*
** Populates the struct member str which stores the read buffer and is to be
** parsed in a later function.  The variable buffer is not used for those
** purposes because it's much more convenient to keep the contents in a struct
** and continually manipulate it if someone puts a PITA buffer size like 1 and
** calls GNL several times.
** This function is followed by a strchr to affirm whether or not the buffer
** that was stored contains a newline char or not.  If not, then the loop
** should continue and more stuff will get appended to str via strjoin.
** If someone could suggest something train related to call this and still keep
** a sense of what this is supposed to do, I'd be grateful.
*/

static int		fill_str(t_block *block, char *buf)
{
	if (!block->str)
		return (0);
	if (!(block->tmp = ft_strjoin(block->str, buf)))
		return (0);
	free(block->str);
	block->str = NULL;
	if (!(block->str = ft_strdup(block->tmp)))
		return (0);
	free(block->tmp);
	block->tmp = NULL;
	return (1);
}

/*
** Due to how I initially visualized GNL, as a bunch of cars being shunted
** around and coupled to the end until there is a caboose added, the train
** theme is somewhat prevalent.  Trains are really cool.  I wrote this with the
** intent of shifting through lists as though cycling through a train
** roundhouse on a turntable.
** C_ASSERT works as ASSERT does, although it returns NULL instead.  The C
** stands for "Char."
*/

static t_block	*station_fd(t_block **train, const int fd)
{
	t_block			*new;

	new = *train;
	while (new && new->fd != fd)
		new = new->next;
	if (!new)
	{
		new = (t_block *)ft_memalloc(sizeof(t_block));
		new->fd = fd;
		C_ASSERT(new->str = ft_strnew(0));
		new->next = *train;
		*train = new;
	}
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_block	*train;
	t_block			*tmp;
	char			buffer[BUFF_SIZE + 1];

	ASSERT(fd >= 0 || line);
	tmp = station_fd(&train, fd);
	while ((tmp->len = read(tmp->fd, &buffer, BUFF_SIZE)) > 0)
	{
		buffer[tmp->len] = '\0';
		ASSERT(fill_str(tmp, buffer));
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	ASSERT(tmp->len >= 0);
	if (!tmp->len && !tmp->str)
	{
		tmp->fd = 0;
		return (0);
	}
	return (parse(&tmp, *line));
}
