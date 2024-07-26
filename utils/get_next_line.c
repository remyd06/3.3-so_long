/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:27:38 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/25 18:27:38 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Function for read the map.ber line by line, use in map_init.c. */

static char	*free_var(char *buffer, char *stash)
{
	if (buffer)
		free(buffer);
	if (stash)
		free(stash);
	return (NULL);
}

static char	*get_stash(char *stash)
{
	int		i;
	int		j;
	char	*temp_stash;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	while (!(stash[i] == '\n' || stash[i] == '\0'))
		i++;
	if (stash[i] == '\0')
		return (free_var(NULL, stash));
	i++;
	temp_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash)));
	if (temp_stash == NULL)
		return (NULL);
	while (stash[i])
	{
		temp_stash[j] = stash[i];
		i++;
		j++;
	}
	temp_stash[j] = '\0';
	free(stash);
	return (temp_stash);
}

static char	*get_line(char *stash)
{
	unsigned int	i;
	char			*line;

	i = 0;
	while (!(stash[i] == '\n' || stash[i] == '\0'))
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*read_line(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (!(ft_strchr(stash, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_var(buffer, stash));
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (stash == NULL)
			return (free_var(buffer, NULL));
	}
	free(buffer);
	if (read_bytes == 0 && stash[read_bytes] == '\0')
		return (free_var(NULL, stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
		stash = ft_strdup("");
	stash = read_line(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = get_line(stash);
	stash = get_stash(stash);
	return (line);
}