/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:41:07 by tlize             #+#    #+#             */
/*   Updated: 2025/04/07 19:46:09 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    char **map = read_map("maps/map1.ber");
    int i = 0;

    if (!map)
    {
        ft_putendl_fd("Erreur de lecture de la carte.\n", 2);
        return (1);
    }
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    return (0);
}