/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char_occurences_in_array.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:03:00 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/23 00:03:00 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* For check_deitex function in map_parsing.c. */
int count_char_occurrences_in_array(t_map *map, char c)
{
    int count;
    int i;
    int j;

    count = 0;
    i = 0;
    while (array[i])
    {
        j = 0;
        while (array[i][j])
        {
            if (array[i][j] == c)
                count++;
            j++;
        }
        i++;
    }

    return count;
}

