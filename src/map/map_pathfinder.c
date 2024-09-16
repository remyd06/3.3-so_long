/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:01:23 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/16 14:01:23 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Entirely frees the floodfill map once the pathfinding is complete.
static void	floodfill_free(t_map *game)
{
	unsigned int	i;

	i = 0;
	while (game->floodfill[i])
	{
		free(game->floodfill[i]);
		i++;
	}
	free(game->floodfill);
}

// Checks if the current position is a coin and adds to the counter.
// Checks if the current position is the exit and adds to the counter.
// Checks if the current position is a wall, exit, or already visited.
// Recursively calls itself to check all four directions.
static int	fill(t_map *game, unsigned int x, unsigned int y)
{
	static int			coins = 0;
	static unsigned int	exit = 0;

	if (game->floodfill[y][x] == 'C')
		coins++;
	if (game->floodfill[y][x] == 'E')
		exit++;
	if (exit && coins == game->count.item)
		return (1);
	if (game->floodfill[y][x] == '1' || game->floodfill[y][x] == 'E'
		|| game->floodfill[y][x] == 'F' || game->floodfill[y][x] == 'H'
		|| game->floodfill[y][x] == 'V')
		return (0);
	game->floodfill[y][x] = 'F';
	if (fill(game, x + 1, y) || fill(game, x, y + 1) || fill(game, x - 1, y)
		|| fill(game, x, y - 1))
		return (1);
	return (0);
}

// Finds player's position to start the pathfinding.
static int	floodfill(t_map *game)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->floodfill[y][x] == 'P')
			{
				game->pos.x = x;
				game->pos.y = y;
				return (fill(game, game->pos.x, game->pos.y));
			}
			x++;
		}
		y++;
	}
	return (0);
}

// Duplicates the map to be used for Flood Fill pathfinding.
static void	floodfill_alloc(t_map *game)
{
	unsigned int	i;
	unsigned int	height;

	i = 0;
	height = game->height;
	game->floodfill = (char **)malloc(sizeof(char *) * (height + 1));
	if (!game->floodfill)
		ft_strerror("Allocation Failed! [./src/map/path_map]");
	while (i < height)
	{
		game->floodfill[i] = ft_strdup((char *)game->map[i]);
		if (!game->floodfill[i])
			ft_strerror("Allocation Failed! [./src/map/path_map]");
		i++;
	}
	game->floodfill[i] = NULL;
}

int	is_valid_path(t_map *game)
{
	int	valid;

	valid = 1;
	floodfill_alloc(game);
	valid = floodfill(game);
	floodfill_free(game);
	if (!valid)
		ft_strerror("\e[1;31m[!] - Fail: \e[1;97mMap is not possible!\n\e[0m");
	else
		ft_putstr("\e[1;32m[✓] - Success: \e[1;97mis_valid_path\n\e[0m");
	return (valid);
}
