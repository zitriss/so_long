/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:28:14 by tlize             #+#    #+#             */
/*   Updated: 2025/04/13 19:49:08 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_rectangle(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->rows)
	{
		if ((int)ft_strlen(game->map[y]) != game->cols)
		{
			perror("Map non rectangulaire\n");
			exit_map(game);
			exit(0);
		}
		y++;
	}
}

void	validate_top_and_bottom_walls(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->cols)
	{
		if (game->map[0][x] != '1' || game->map[game->rows - 1][x] != '1')
		{
			perror("Murs incorrects\n");
			exit_map(game);
			exit(0);
		}
		x++;
	}
}

void	validate_side_walls(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->rows)
	{
		if (game->map[y][0] != '1' || game->map[y][game->cols - 1] != '1')
		{
			perror("Murs incorrects\n");
			exit_map(game);
			exit(0);
		}
		y++;
	}
}

void	validate_walls_and_rectangle(t_game *game)
{
	validate_rectangle(game);
	validate_top_and_bottom_walls(game);
	validate_side_walls(game);
}
