/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:59:32 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/16 14:10:41 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_assets(t_map *game)
{
	int	i;

	i = TILES;
	game->mlx.player = mlx_xpm_file_to_image(game->mlx.mlx,
			"src/game/assets/player.xpm", &i, &i);
	game->mlx.exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"src/game/assets/exit.xpm", &i, &i);
	game->mlx.item = mlx_xpm_file_to_image(game->mlx.mlx,
			"src/game/assets/item.xpm", &i, &i);
	game->mlx.ground = mlx_xpm_file_to_image(game->mlx.mlx,
			"src/game/assets/ground.xpm", &i, &i);
	game->mlx.wall = mlx_xpm_file_to_image(game->mlx.mlx,
			"src/game/assets/wall.xpm", &i, &i);
}
