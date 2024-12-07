#include <stdio.h>
#include "../get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd, fd0, fd1;
	char	*b;
	int	i;

	i = 0;	
	fd0 = open("t", O_CREAT, O_RDONLY);
	fd1 = open("y", O_CREAT, O_RDONLY);
	fd = fd0;
	while (b = get_next_line(fd))
	{
		if (++i % 2)
			fd = fd1;
		else
			fd = fd0;
		printf("line : %s", b);
		free(b);
	}
	/*b = get_next_line(fd0);*/
	/*printf("\n%s\n", b);*/
	return (0);
}
