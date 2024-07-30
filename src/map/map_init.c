/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:47:14 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/21 17:47:14 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Calculate the map volume for malloc. */
int	map_volume(int fd)
{
	int		count;
	char	buffer;
	int		byte_read;

	count = 0;
	buffer = 0;
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, &buffer, 1);
		if (buffer == '\n')
			count++;
	}
	if (buffer != '\n' && byte_read == 0)
		count++;
	close(fd);
	return (count);
}

/* Check if map.ber open without error and malloc the map array. */
void	checkfd_malloc(int fd, char **return_map)
{
	if (fd == -1)
	{
		ft_strerror("Error file not found.");
		return (NULL);
	}
	return_map = (const char**)malloc(sizeof(const char *) * (map_volume(fd) + 1));
	if (!return_map)
	{
		ft_strerror("Memory allocation for map has failed.");
		close(fd);
		return (NULL);
	}
}

/* Read and put he map of the .ber in an **array */
char	**map_init(const char *filename)
{
	char	**return_map;
	char	*line;
	int		fd;
	int		i;

	max_line = 7;
	fd = open(filename, O_RDONLY);
	checkfd_malloc(fd, return_map);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		return_map[i] = line;
		i++;
	}
	return_map[i] = '\0';
	close(fd); 
	return (return_map);
}