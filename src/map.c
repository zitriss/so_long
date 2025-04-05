/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:28:40 by tlize             #+#    #+#             */
/*   Updated: 2025/04/05 16:35:52 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char **read_map(const char *filename)
{
    char    *line;
    char    *sumline = NULL;
    char    **map;
    int     fd;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    while((line = get_next_line(fd)))
    {
        sumline = ft_strjoin(sumline, line);
        free(line);
    }
    close(fd);
    map = ft_split(sumline, '\n');
    free(sumline);
    return (map);
}