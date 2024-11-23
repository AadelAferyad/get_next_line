/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:47:31 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/23 23:18:21 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_for_new_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	if (buffer)
}

char	*read_line(int fd, char *line)
{
	char	*buffer;
	int		i;
	int		byte;

	i = 0;
	byte = 1;
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	while (byte && buffer[i] != '\n' && byte <= BUFFER_SIZE)
	{
		byte = read(fd, buffer, 1);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (check_for_new_line(buffer))
		i++;
	}

}

char	*get_next_line(int fd)
{
	static char	*line;

	read_line(fd, line);
}
