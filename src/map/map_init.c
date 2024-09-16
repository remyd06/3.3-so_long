/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:29:24 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/16 13:29:24 by rdedola          ###   ########.fr       */
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
int	checkfd_malloc(int fd, t_map *game)
{
	int	i;

	i = map_volume(fd);
	if (fd == -1)
	{
		ft_strerror("Error file not found.");
		exit(1);
	}
	game->map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!game->map)
	{
		ft_strerror("Memory allocation for map has failed.");
		close(fd);
		exit(1);
	}
	close(fd);
	return (i);
}

/* Read and put he map of the .ber in an **array */
void	map_init(const char *filename, t_map *game)
{
	int	fd;
	int	i;
	int	max;

	fd = open(filename, O_RDONLY);
	max = checkfd_malloc(fd, game);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < max)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}
