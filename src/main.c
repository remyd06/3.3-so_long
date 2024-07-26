/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:11:16 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/22 09:11:16 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* For check if the only argument is the map path file and if it is a .ber file. */
void    main_parser(int argc, char **argv)
{
    int i;

    i = 0;
	if (argc != 2)
    {
        ft_strerror("Only the file path in argument.")
        return (0);
    }
    while (argv[1][i])
        i++;
    if ((argv[1][i - 4] != '.') && (argv[1][i - 3] != 'b') && (argv[1][i - 4] != 'e') &&
     (argv[1][i - 4] != 'r'))
     {
        ft_strerror("Wrong map file.");
        return ;
     }
}

int	main(int argc, char **argv)
{
    t_map map;
    
    main_parser(argc, argv);
    map.map = map_init(argv[1]);
    map_parsing(&map);
}