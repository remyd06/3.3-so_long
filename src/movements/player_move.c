/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:07:00 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/16 15:50:31 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	redraw(t_map *game, unsigned int x, unsigned int y)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.ground,
		game->pos.x * TILES, game->pos.y * TILES);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.player, x
		* TILES, y * TILES);
}

void	player_move(t_map *game, unsigned int x, unsigned int y)
{
	static int	count;

	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->count.item--;
		redraw(game, x, y);
		game->map[game->pos.y][game->pos.x] = '0';
		game->map[y][x] = 'P';
		game->pos.x = x;
		game->pos.y = y;
		ft_putnbr(count++);
		write(1, "\n", 1);
	}
	else if (game->map[y][x] == '1')
		return ;
	else if (game->map[y][x] == 'E' && game->count.item == 0)
	{
		ft_putstr("YOU WIN!\n");
		close_window(game);
	}
}
