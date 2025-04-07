/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:26:25 by tlize             #+#    #+#             */
/*   Updated: 2025/04/07 21:26:47 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_map_rectangular(char **map)
{
    size_t first_len;
    int i;

    if (!map || !map[0])
        return (0);
    first_len = ft_strlen(map[0]);
    i = 1;
    while (map[i])
    {
        if (ft_strlen(map[i]) != first_len)
            return (0);
        i ++;
    }
    return (1);
}

int check_walls(char **map)
{
    size_t len;
    int i;
    int j;

    i = 0;
    if (!map || !map[0])
        return (0);
    len = ft_strlen(map[0]);
    while(map[0][i])
    {
        if (map[0][i] != '1')
            return (0);
        i ++;
    }
    i = 1;
    while(map[i + 1])
    {
        if (map[i][0] != '1' || map[i][len - 1] != '1')
            return (0);
        i ++;
    }
    j = 0;
    while(map[i][j])
    {
        if (map[i][j] != '1')
            return (0);
        j ++;
    }
    return (0);
}