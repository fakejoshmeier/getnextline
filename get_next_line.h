/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 09:05:17 by jmeier            #+#    #+#             */
/*   Updated: 2017/10/29 19:52:49 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 32
# define ASSERT(a) if (!(a)) return (-1);
# define C_ASSERT(a) if (!(a)) return (NULL);

typedef struct		s_block
{
	char			*str;
	char			*tmp;
	int				len;
	int				fd;
	struct s_block	*next;
}					t_block;

int					get_next_line(const int fd, char **line);

#endif
