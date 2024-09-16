/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:36:42 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/16 14:12:39 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_game(t_map *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
	{
		ft_strerror("Mlx initialization has failed");
		return ;
	}
	game->mlx.win = mlx_new_window(game->mlx.mlx, (game->width - 1) * TILES,
			game->height * TILES, "so_long by rdedola");
	if (!game->mlx.win)
	{
		ft_strerror("Windows creation has failed");
		return ;
	}
}
