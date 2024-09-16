/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:29:32 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/16 13:29:32 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* For check if the only argument is
 the map path file and if it is a .ber file. */
void	main_parser(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_strerror("Only the file path in argument.");
		exit (1);
	}
	while (argv[1][i])
		i++;
	if ((argv[1][i - 4] != '.') && (argv[1][i - 3] != 'b') && (argv[1][i
			- 4] != 'e') && (argv[1][i - 4] != 'r'))
	{
		ft_strerror("Wrong map path file.");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_map	*game;

	game = (t_map *)malloc(sizeof(t_map));
	main_parser(argc, argv);
	map_init(argv[1], game);
	map_parsing(game);
	init_game(game);
	load_assets(game);
	print_walls(game);
	print_ground(game);
	print_item(game);
	print_exit(game);
	print_player(game);
	mlx_hook(game->mlx.win, 2, (1L << 0), handle_keypress, game);
	mlx_hook(game->mlx.win, 17, 0L, close_window, game);
	mlx_loop(game->mlx.mlx);
}
