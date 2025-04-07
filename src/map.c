/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:28:40 by tlize             #+#    #+#             */
/*   Updated: 2025/04/07 19:55:53 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char **read_map(const char *filename)
{
    char    *line;
    char    *tmp;
    char    *sumline;
    char    **map;
    int     fd;

    sumline = ft_strdup("");
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    
    while((line = get_next_line(fd)))
    {
        tmp = sumline;
        sumline = ft_strjoin(sumline, line);
        free(tmp);
        free(line);
    }
    close(fd);
    map = ft_split(sumline, '\n');
    free(sumline);
    return (map);
}