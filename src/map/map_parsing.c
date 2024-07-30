/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:47:34 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/21 17:47:34 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Check if there is only 1, 0, P, C, E in the map. */
void check_only_needs(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != 'P' &&
			 game->map[i][j] != 'C' && game->map[i][j] != 'E')
			 {
			 	ft_strerror("Wrong map asset, only 1, 0, P, C, E");
				free_map(game);
				return ;
			 }
			j++;
		}
		i++;
	}
}

/* Check if there is rights occurences of each needs. */
void check_deitex(t_map *game)
{

    game->begin = count_char_occurrences_in_array(game, 'P');
    game->item = count_char_occurrences_in_array(game, 'C');
    game->exit = count_char_occurrences_in_array(game, 'E');
    if (game->item < 1 || game->exit != 1 || game->begin != 1)
    {
        if (game->begin != 1)
            ft_strerror("There should be exactly one starting point (P)");
        if (game->item < 1)
            ft_strerror("There should be at least one item (C)");
        if (game->exit != 1)
            ft_strerror("There should be exactly one exit (E)");
		free_map(game);
        return ;
    }
}

/* Check if the map is a perfect rectangle. */
void	is_rectangle(t_map *game)
{
	int i;
    int ref_width;

	i = 0;
	ref_width = ft_strlen(game->map[0]);
	while (game->map[i])
    {
        if (ft_strlen(game->map[i]) != ref_width)
        {
            ft_strerror("Map is not a rectangle");
            free_map(game);
            return;
        }
        i++;
    }
	game->height = i;
    game->width = ref_width;
	if ((game->height) == game->width)
	{
		ft_strerror("Map is not a rectangle but a square");
		free_map(game);
		return ;
	}
}

/* Check if the map is well surronded by walls. */
void	check_surronded(t_map *game)
{
	int	map_length;
	int map_width;

	map_length = 0;
	while (game->map[map_length])
		map_length++;
	map_width = 0;
	while (game->map[0][map_width])
		map_width++;
	check_walls(game, map_length, map_width);
}

/* Parsing of the map. */
void	map_parsing(t_map *game)
{
	if (game->map == NULL)
	{
		ft_strerror("The map is empty.");
		return ;
	}
	check_only_needs(game);
	check_deitex(game);
	is_rectangle(game);
	check_surronded(game);
}
