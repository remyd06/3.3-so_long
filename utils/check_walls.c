/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:40:01 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/25 14:40:01 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* For check_surronded function in map_parsing.c. */
void    check_walls(t_map *map, int map_length, int map_width)
{
    int i;

    i = 0;
 	while (i < map_length) 
	{
        if (map[0][i] != '1' || map[map_length - 1][i] != '1') 
		{
            ft_strerror("Map is not surrounded by walls");
			free_map(map);
            return ;
		}
		i++;
	}
	i = 0;
	while (i < map_width) 
	{
		if (map[i][0] != '1' || map[i][map_width - 1] != '1') 
		{
			ft_strerror("Map is not surrounded by walls");
			free_map(map);
			return ;
		}
		i++;
	}
}