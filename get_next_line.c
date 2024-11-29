/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:47:31 by aaferyad          #+#    #+#             */
/*   Updated: 2024/11/29 12:57:37 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*read_line(int fd)
{
	char	*buffer;
	int		i;
	int		byte;

	i = 0;
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	byte = read(fd, &buffer[i], 1);
	while (byte && buffer[i++] != '\n' && i <= BUFFER_SIZE)
	{
		byte = read(fd, &buffer[i], 1);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{

	return (read_line(fd));
}
