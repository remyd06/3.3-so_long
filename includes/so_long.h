/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:24:49 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/21 17:24:49 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#include <unistd.h>	// write(), read()
#include <stdio.h>		// printf()
#include<stdlib.h>	//malloc(), free()
#include <fcntl.h>		// open()
#include "mlx.h"    //Minilibx

/* Buffer set for get_next_line. */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Read facilities who return true or false in a function. */
typedef enum    e_bool
{
	false = 0,
	true = 1
}	t_bool;

struct  s_pos
{
    unsigned int x;
    unsigned int y;
};

/* Structure who contains all elements of game. */
typedef struct  s_map
{
    struct          s_pos;
    const char      **map;
    char            **floodfill;
    unsigned int    height;
    unsigned int    width;
    int             begin;
    int             item;
    int             exit;

}   t_map;

/* Utils */
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char target);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strdup(char *str);
void    ft_strerror(const char *str);
void    free_map(t_map *game);
int		count_char_occurrences_in_array(t_map *game, char c);
void    check_walls(t_map *game, int map_length, int map_width);

/* Map */
char	**map_init(const char *filename);
void	map_parsing(t_map *game);
void    map_pathfinder(t_map *game);


#endif