/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_chemin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:22:06 by tlize             #+#    #+#             */
/*   Updated: 2025/04/13 16:29:04 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**clone_map(t_game *game)
{
	int		i;

	game->clone = malloc(game->rows * sizeof(char *));
	if (!game->clone)
	{
		perror("Error\nMemory allocation failed for map clone.\n");
		exit(0);
	}
	i = 0;
	while (i < game->rows)
	{
		game->clone[i] = ft_strdup(game->map[i]);
		if (!game->clone[i])
		{
			perror("Error\nallocation a echoue.\n");
			while (--i >= 0)
				free(game->clone[i]);
			free(game->clone);
			exit(0);
		}
		i++;
	}
	return (game->clone);
}

void	free_clone(t_game *game, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(game->clone[i]);
		i++;
	}
	free(game->clone);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->cols || y < 0 || y >= game->rows
		|| game->clone[y][x] == '1' || game->clone[y][x] == 'V')
		return ;
	game->clone[y][x] = 'V';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	check_unreachable_collectibles(t_game *game,
			char **map, int rows, int cols)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == 'C' && game->clone[y][x] != 'V')
			{
				perror("Error\nCollectible non atteignable.\n");
				free_clone(game, rows);
				exit_map(game);
				exit(0);
			}
			x++;
		}
		y++;
	}
}

void	check_unreachable_exit(t_game *game, char **map,
		int rows, int cols)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == 'E' && game->clone[y][x] != 'V')
			{
				perror("Error\nSortie non atteignable.\n");
				free_clone(game, rows);
				exit_map(game);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

