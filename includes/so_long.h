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

/* Structure who contains all elements of game. */
typedef struct s_map
{
    const char **map;
    int         player;
    int         item;
    int         exit;

}   t_map;

/* Utils */
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char target);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strdup(char *str);
void    ft_strerror(const char *str);
void    free_map(t_map *map);
int		count_char_occurrences_in_array(t_map *map, char c);
void    check_walls(t_map *map, int map_length, int map_width);

/* Map */
char	**map_init(const char *filename);
void	map_parsing(t_map *map);
void    map_pathfinder(t_map *map);


#endif