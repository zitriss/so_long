/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:41:07 by tlize             #+#    #+#             */
/*   Updated: 2025/04/05 16:32:09 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    char **map = parse_map("maps/map1.ber");
    if (!map)
    {
        printf("Erreur lors du chargement de la map\n");
        return(1);
    }
    for (int i = 0; map[i]; i++)
        printf("%s\n", map[i]);
    return (0);
}