/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:55:52 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/16 14:11:56 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	print_player(t_map *game)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	y_offset;
	unsigned int	x_offset;

	y = 0;
	y_offset = 0;
	while (y < game->height)
	{
		x = 0;
		x_offset = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
					game->mlx.player, x_offset, y_offset);
			}
			x_offset += TILES;
			x++;
		}
		y_offset += TILES;
		y++;
	}
}
