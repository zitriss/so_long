/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:50:43 by tlize             #+#    #+#             */
/*   Updated: 2025/01/06 10:14:39 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*strjoinfree(char *str, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(str, buffer);
	free(str);
	return (temp);
}

static char	*read_memory(int fd, char *memory)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (!memory)
		memory = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(memory, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(memory);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		memory = strjoinfree(memory, buffer);
	}
	free (buffer);
	return (memory);
}

static char	*get_memory(char *memory)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!memory || !*memory)
		return (NULL);
	while (memory[i] && memory[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (free(line), NULL);
	i = 0;
	while (memory[i] && memory[i] != '\n')
	{
		line[i] = memory[i];
		i ++;
	}
	if (memory[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*trim_memory(char *memory)
{
	size_t	i;
	size_t	j;
	char	*new_memory;

	i = 0;
	j = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (!memory[i])
		return (free (memory), NULL);
	new_memory = ft_calloc((ft_strlen(memory) - i + 1), sizeof(*memory));
	if (!new_memory)
		return (free (memory), NULL);
	i++;
	while (memory[i])
		new_memory[j++] = memory[i++];
	new_memory[j] = '\0';
	free (memory);
	return (new_memory);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	memory = read_memory(fd, memory);
	if (!memory)
		return (NULL);
	current_line = get_memory(memory);
	memory = trim_memory(memory);
	return (current_line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }