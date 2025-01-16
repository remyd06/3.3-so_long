/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:54:56 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/10 14:57:13 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	destroy_sprite(t_map *game)
{
	mlx_destroy_image(game->mlx.mlx, game->mlx.player);
	mlx_destroy_image(game->mlx.mlx, game->mlx.item);
	mlx_destroy_image(game->mlx.mlx, game->mlx.exit);
	mlx_destroy_image(game->mlx.mlx, game->mlx.wall);
	mlx_destroy_image(game->mlx.mlx, game->mlx.ground);
}

int	close_window(t_map *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	destroy_sprite(game);
	free_map(game);
	ft_putstr("Game closed!\n");
	exit (0);
	return (0);
}
