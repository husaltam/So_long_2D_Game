/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/06/09 13:16:51 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
* check if the map doesn't have any extra lines
*/
static int	is_map_valid(char *content)
{
	int	i;

	if (!content || content[0] == '\0')
		return (0);
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n' && content[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

/**
	Read the entire content of a file into a single string using get_next_line.
	- Concatenates lines one by one.
	- Handles memory allocation and cleanup.
	Returns a pointer to the full content string or NULL on error.
*/
static char	*read_entire_file(int fd)
{
	char	*content;
	char	*line;
	char	*tmp;

	content = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!content)
			content = line;
		else
		{
			tmp = content;
			content = ft_strjoin(tmp, line);
			free(tmp);
			free(line);
			if (!content)
				return (NULL);
		}
		line = get_next_line(fd);
	}
	return (content);
}

/**
	Read and parse a map file.
	- Opens the file, reads its content into a string, then splits it into lines.
	- Frees temporary content and handles errors.
	Returns a NULL-terminated array of strings representing the map.
*/
char	**parse_map_file(char *path)
{
	int		fd;
	char	*file_content;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_content = read_entire_file(fd);
	close(fd);
	if (!is_map_valid(file_content))
	{
		free(file_content);
		return (NULL);
	}
	map = ft_split(file_content, '\n');
	free(file_content);
	return (map);
}
