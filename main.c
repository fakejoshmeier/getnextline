#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char		*file;
	char		*line;
	int			fd;

	void(argc);
	file = argv[1];
	fd = open(file, 0_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("LINES: \"%s\"\n", line);
		free(line);
	}
	return (0);
}
