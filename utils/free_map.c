/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:27:50 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/25 15:27:50 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* For free the map incase of error. */
void    free_map(t_map *game)
{
    int i;

    i = 0;
    while(game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
}