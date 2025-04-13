/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:15:43 by tlize             #+#    #+#             */
/*   Updated: 2025/04/13 19:45:51 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(const char *file, t_game *game)
{
	calculate_map_dimensions(file, game);
	allocate_map_memory(game);
	fill_map_from_file(file, game);
	initialize_game_elements(game);
	return (game->map);
}

void	init_game(t_game *game, const char *map_file)
{
	game->move_count = 0;
	game->map = read_map(map_file, game);
	validate_playable_map(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->cols * TILE_SIZE,
			game->rows * TILE_SIZE, "so_long");
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"assets/mer.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"assets/sand.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"assets/tralalero.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"assets/chaussure.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"assets/tralala.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->wall_img || !game->floor_img || !game->player_img
		|| !game->collectible_img || !game->exit_img)
	{
		perror("Erreur lors du chargement des images\n");
		exit_game(game);
	}
	draw_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		perror("Nombres d'arguments incorrect\n");
		return (1);
	}
	init_game(&game, argv[1]);
	mlx_hook(game.win, 2, 1L << 0, on_keypress, &game);
	mlx_hook(game.win, DestroyNotify,
		StructureNotifyMask, &on_destroy_bouton, &game);
	mlx_loop(game.mlx);
	exit_game(&game);
	return (0);
}
