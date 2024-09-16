/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:39:24 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/16 15:13:01 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	handle_keypress(int key, t_map *game)
{
	unsigned int	x;
	unsigned int	y;

	x = game->pos.x;
	y = game->pos.y;
	if (key == ESC)
		close_window(game);
	else if (key == W)
		player_move(game, x, y - 1);
	else if (key == A)
		player_move(game, x - 1, y);
	else if (key == S)
		player_move(game, x, y + 1);
	else if (key == D)
		player_move(game, x + 1, y);
	return (0);
}
