/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/21 17:24:49 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/21 17:24:49 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"    //Minilibx
# include <fcntl.h>  // open()
# include <stdio.h>  // printf()
# include <stdlib.h> //malloc(), free()
# include <unistd.h> // write(), read()

/* Buffer set for get_next_line. */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Size of one block */
# define TILES 48

/* Replace keycodes of keyboard by keynames */

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

/* Position of the player */
struct s_pos
{
	unsigned int	x;
	unsigned int	y;
};

/* Count of each */
struct s_count
{
	int	begin;
	int	item;
	int	exit;
	int	count;
};

/* Structure for mlx lib*/
struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*item;
	void	*exit;
	void	*ground;
	void	*wall;
};

/* Structure who contains all elements of game. */
typedef struct s_map
{
	struct s_pos	pos;
	struct s_count	count;
	struct s_mlx	mlx;
	char			**map;
	char			**floodfill;
	unsigned int	height;
	unsigned int	width;
}	t_map;

/* Utils */
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char target);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strdup(char *str);
void	ft_putstr(char *str);
void	ft_strerror(const char *str);
void	free_map(t_map *game);
void	ft_putnbr(unsigned int n);
int		count_char_occurrences_in_array(t_map *game, char c);
void	check_walls(t_map *game, int map_length, int map_width);

/* Map */
void	map_init(const char *filename, t_map *game);
void	map_parsing(t_map *game);
int		is_valid_path(t_map *game);

/* Game */
void	init_game(t_map *game);
void	load_assets(t_map *game);
void	print_walls(t_map *game);
void	print_ground(t_map *game);
void	print_item(t_map *game);
void	print_exit(t_map *game);
void	print_player(t_map *game);

/* Movements */
int		handle_keypress(int key, t_map *game);
int		close_window(t_map *game);
void	player_move(t_map *game, unsigned int x, unsigned int y);

#endif