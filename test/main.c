#include <stdio.h>
#include "../get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd, fd0, fd1;
	char	*b;

	
	fd0 = open("t", O_CREAT, O_RDONLY);
	fd1 = open("y", O_CREAT, O_RDONLY);
	while (b = get_next_line(fd0))
	{
		printf("line : %s", b);
		free(b);
	}
	b = get_next_line(fd0);
	printf("%s", b);
	return (0);
}
