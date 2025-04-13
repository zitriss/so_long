/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:21:20 by tlize             #+#    #+#             */
/*   Updated: 2025/04/13 16:21:44 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_map_dimensions(const char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nOuverture du fichier impossible\n");
		exit(0);
	}
	game->rows = 0;
	game->cols = 0;
	line = get_next_line(fd);
	while ((line))
	{
		if (game->cols == 0)
			game->cols = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
		game->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	allocate_map_memory(t_game *game)
{
	int	i;

	i = 0;
	game->map = malloc(game->rows * sizeof(char *));
	if (!game->map)
	{
		perror("Error\nÉchec d'allocation mémoire pour la carte.\n");
		exit_game(game);
	}
	while (i < game->rows)
	{
		game->map[i] = NULL;
		i++;
	}
}

void	fill_map_line(char *line, t_game *game, int row)
{
	if (!line)
	{
		perror("Error\nLigne invalide.\n");
		exit_game(game);
	}
	game->map[row] = malloc((game->cols + 1) * sizeof(char));
	if (!game->map[row])
	{
		perror("Error\nÉchec d'allocation mémoire pour une ligne.\n");
		exit_game(game);
	}
	ft_strncpy(game->map[row], line, game->cols);
	game->map[row][game->cols] = '\0';
}

void	fill_map_from_file(const char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nImpossible d'ouvrir le fichier\n");
		exit(0);
	}
	i = 0;
	while (i < game->rows)
	{
		line = get_next_line(fd);
		if (!line)
		{
			perror("Error\nProblème lecture de la carte.\n");
			exit_game(game);
		}
		fill_map_line(line, game, i);
		free(line);
		i++;
	}
	close(fd);
}

void	initialize_game_elements(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->collectibles = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map[y][x] == 'C')
			{
				game->collectibles++;
			}
			x++;
		}
		y++;
	}
}