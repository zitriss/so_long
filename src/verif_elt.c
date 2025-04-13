/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_elt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:22:46 by tlize             #+#    #+#             */
/*   Updated: 2025/04/13 18:45:51 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(t_game *game, int player_count,
			int exit_count, int collectible_count)
{
	if (player_count != 1)
	{
		perror("Normalent il passe pas par la.\n");
		exit_map(game);
		exit(0);
	}
	if (exit_count != 1)
	{
		perror("Pas de sortie.\n");
		exit_map(game);
		exit(0);
	}
	if (collectible_count < 1)
	{
		perror("Pas de chaussure.\n");
		exit_map(game);
		exit(0);
	}
}

void	count_map_elements(t_game *game,
	int *player_count, int *exit_count, int *collectible_count)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			tile = game->map[y][x];
			if (tile == 'P')
				(*player_count)++;
			else if (tile == 'E')
				(*exit_count)++;
			else if (tile == 'C')
				(*collectible_count)++;
			x++;
		}
		y++;
	}
}

void	validate_map(t_game *game)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	count_map_elements(game, &player_count, &exit_count, &collectible_count);
	error_message(game, player_count, exit_count, collectible_count);
}

void	check_reachability(t_game *game)
{
	game->clone = clone_map(game);
	flood_fill(game, game->player_x,
		game->player_y);
	check_unreachable_collectibles(game, game->map,
		game->rows, game->cols);
	check_unreachable_exit(game, game->map,
		game->rows, game->cols);
	free_clone(game, game->rows);
}

void	validate_playable_map(t_game *game)
{
	validate_walls_and_rectangle(game);
	validate_map(game);
	check_reachability(game);
}