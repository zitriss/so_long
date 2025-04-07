/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:41:07 by tlize             #+#    #+#             */
/*   Updated: 2025/04/07 21:27:48 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    char **map = read_map("maps/map1.ber");
    int i = 0;

    if (!map)
        return (ft_putendl_fd("Erreur de lecture de la carte.\n", 2), 1);
    if (!is_map_rectangular(map))
        return (ft_putendl_fd("Erreur, la carte n'est pas rectangulaire", 2), 1);
    if (!check_walls(map))
	    return (ft_putendl_fd("Erreur : map pas entourée de murs", 2), 1);
    while (map[i])
        printf("%s\n", map[i++]);
    return (0);
}