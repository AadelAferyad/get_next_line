/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:02:20 by aaferyad          #+#    #+#             */
/*   Updated: 2024/12/05 17:08:18 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	garbage_collector(char *lines, char *buffer, int flag)
{
	if (!flag)
	{
		free(buffer);
		buffer = NULL;
	}
	else if (flag == 1)
	{
		free(lines);
		lines = NULL;
	}
	else if (flag == 2)
	{
		free(buffer);
		buffer = NULL;
		free(lines);
		lines = NULL;
	}
}

char	*extract_line_helper(char *lines, unsigned int *size)
{
	char	*new_line_add;

	new_line_add = ft_strchr(lines, '\n');
	if (!new_line_add)
		new_line_add = ft_strchr(lines, '\0');
	*size = new_line_add - lines + 1;
	return (new_line_add);
}

char	*extract_line(char **lines, int fd)
{
	char			*new_line_add;
	char			*line;
	unsigned int	size;

	if (!(lines[fd]))
		return (NULL);
	new_line_add = extract_line_helper(lines[fd], &size);
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
	{
		garbage_collector(lines[fd], NULL, 1);
		return (NULL);
	}
	ft_strlcpy(line, lines[fd], size + 1);
	if (!(*new_line_add) || !(*(new_line_add + 1)))
	{
		garbage_collector(lines[fd], NULL, 1);
		return (line);
	}
	new_line_add = ft_strdup(new_line_add + 1);
	garbage_collector(lines[fd], NULL, 1);
	lines[fd] = new_line_add;
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
		if (byte == -1)
		{
			garbage_collector(lines[fd], buffer, 2);
			return (NULL);
		}
		if (byte == 0)
			break ;
		buffer[byte] = '\0';
		lines[fd] = ft_strjoin(*lines, buffer);
	}
	garbage_collector(lines[fd], buffer, 0);
	return (extract_line(lines, fd));
}

char	*get_next_line(int fd)
{
	static char	*lines[MAX_FD];

	if (fd > MAX_FD)
		return (NULL);
	return (read_line(fd, lines));
}
