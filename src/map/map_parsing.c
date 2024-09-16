/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:29:45 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/16 13:29:45 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Check if there is only 1, 0, P, C, E in the map. */
void	check_only_needs(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E' && game->map[i][j] != '\r'
				&& game->map[i][j] != '\n')
			{
				ft_strerror("Wrong map asset, only 1, 0, P, C, E");
				free_map(game);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

/* Check if there is rights occurences of each needs. */
void	check_deitex(t_map *game)
{
	game->count.begin = count_char_occurrences_in_array(game, 'P');
	game->count.item = count_char_occurrences_in_array(game, 'C');
	game->count.exit = count_char_occurrences_in_array(game, 'E');
	if (game->count.item < 1 || game->count.exit != 1
		|| game->count.begin != 1)
	{
		if (game->count.begin != 1)
			ft_strerror("There should be exactly one starting point (P)");
		if (game->count.item < 1)
			ft_strerror("There should be at least one item (C)");
		if (game->count.exit != 1)
			ft_strerror("There should be exactly one exit (E)");
		free_map(game);
		exit(1);
	}
}

/* Check if the map is a perfect rectangle. */
void	is_rectangle(t_map *game)
{
	int		i;
	size_t	ref_width;

	i = 0;
	ref_width = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != ref_width)
		{
			ft_strerror("Map is not a rectangle");
			free_map(game);
			exit(1);
		}
		i++;
	}
	game->height = i;
	game->width = ref_width;
	if (game->height == game->width)
	{
		ft_strerror("Map is not a rectangle but a square");
		free_map(game);
		exit(1);
	}
}

/* Check if the map is well surronded by walls. */
void	check_surronded(t_map *game)
{
	unsigned int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 2] != '1')
		{
			ft_strerror("Map is not surrounded by walls");
			free_map(game);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < game->width - 2)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			ft_strerror("Map is not surrounded by walls");
			free_map(game);
			exit(1);
		}
		i++;
	}
}

/* Parsing of the map. */
void	map_parsing(t_map *game)
{
	if (game->map == NULL)
	{
		ft_strerror("The map is empty.");
		exit(1);
	}
	check_only_needs(game);
	check_deitex(game);
	is_rectangle(game);
	check_surronded(game);
	is_valid_path(game);
}
