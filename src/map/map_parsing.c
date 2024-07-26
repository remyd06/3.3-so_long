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
void check_only_needs(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != 'P' &&
			 map->map[i][j] != 'C' && map->map[i][j] != 'E')
			 {
			 	ft_strerror("Wrong map asset, only 1, 0, P, C, E");
				free_map(map);
				return ;
			 }
			j++;
		}
		i++;
	}
}

/* Check if there is rights occurences of each needs. */
void check_deitex(t_map *map)
{
    int begin;
    int item;
    int exit;

    begin = count_char_occurrences_in_array(map->map, 'P');
    item = count_char_occurrences_in_array(map->map, 'C');
    exit = count_char_occurrences_in_array(map->map, 'E');
    if (item < 1 || exit != 1 || begin != 1)
    {
        if (begin != 1)
            ft_strerror("There should be exactly one starting point (P)");
        if (item < 1)
            ft_strerror("There should be at least one item (C)");
        if (exit != 1)
            ft_strerror("There should be exactly one exit (E)");
		free_map(map);
        return ;
    }
}

/* Check if the map is a perfect rectangle. */
void	is_rectangle(t_map *map)
{
	int	i;
	int	str_length;
	int	current_str_length;

	i = 0;
	str_length = 0;
	while (map->map[0][str_length])
		str_length++;
	while (map->map[i])
	{
		current_str_length = 0;
		while (map->map[i][current_str_length])
			current_str_length++;
		if (current_str_length != str_length)
		{
			ft_strerror("Map is not a rectangle");
			return ;
		}
		i++;
	}
	if (i == str_length)
	{
		ft_strerror("Map is not a rectangle");
		return ;
	}
}

/* Check if the map is well surronded by walls. */
void	check_surronded(t_map *map)
{
	int	map_length;
	int map_width;

	map_length = 0;
	while (map->map[map_length])
		map_length++;
	map_width = 0;
	while (map->map[0][map_width])
		map_width++;
	check_walls(map, map_length, map_width);
}

/* Parsing of the map. */
void	map_parsing(t_map *map)
{
	if (map == NULL || map->map == NULL)
	{
		ft_strerror("The map is empty.");
		return ;
	}
	check_only_needs(map);
	check_deitex(map);
	is_rectangle(map);
	check_surronded(map);
}
