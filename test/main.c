#include <stdio.h>
#include "../get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd, fd0, fd1;
	int	i;
	char	*b;

	
	fd0 = open("t", O_CREAT, O_RDONLY);
	fd1 = open("y", O_CREAT, O_RDONLY);
	i = 0;
	do
	{
		if (i % 2)
			fd = fd0;
		else
			fd = fd1;
		b = get_next_line(fd);
		i++;
		if (!b)
			break ;
		printf("%s\n", b);
		free(b);
	} while (b);


	return (0);
}
