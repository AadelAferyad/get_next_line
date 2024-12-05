/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:02:20 by aaferyad          #+#    #+#             */
/*   Updated: 2024/12/05 15:19:01 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((unsigned char) c == 0)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*extract_line(char **lines)
{
	char	*new_line_add;
	char	*line;
	unsigned int	size;

	new_line_add = ft_strchr(*lines, '\n');	
	if (!new_line_add)
		new_line_add = ft_strchr(*lines, '\0');
	size = new_line_add - *lines;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
	{
		free(lines);
		return (NULL);
	}
	ft_strlcpy(line, *lines, size + 1);
	if (!(*new_line_add))
	{
		free(*lines);
		return (line);
	}
	new_line_add = ft_strdup(new_line_add + 1);
	free(*lines);
	*lines = new_line_add;
	return (line);
}

char	*read_line(int fd, char **lines)
{
	char	*buffer;
	int		byte;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(*lines, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte <= 0)
		{
			free(buffer);
			free(*lines);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		*lines = ft_strjoin(*lines, buffer);
	}
	free(buffer);
	return (extract_line(lines));
}

char	*get_next_line(int fd)
{
	static char *lines;

	return (read_line(fd, &lines));
}
