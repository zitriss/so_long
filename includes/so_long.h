/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:40:23 by tlize             #+#    #+#             */
/*   Updated: 2025/04/13 20:46:53 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define TILE_SIZE 54

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		collectibles;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
	int		move_count;
	char	**clone;		
}	t_game;

//Fonctions de map
void	draw_map(t_game *game);
char	**read_map(const char *file, t_game *game);
int		main(int argc, char **argv);
void	validate_side_walls(t_game *game);
void	validate_top_and_bottom_walls(t_game *game);
void	validate_rectangle(t_game *game);
void	calculate_map_dimensions(const char *file, t_game *game);
void	allocate_map_memory(t_game *game);
void	fill_map_from_file(const char *file, t_game *game);
void	initialize_game_elements(t_game *game);
void	fill_map_line(char *line, t_game *game, int row);

//Mouvements
void	move_player(t_game *game, int dx, int dy);
int		on_keypress(int keycode, t_game *game);

//Verifs map et en jeu
void	validate_map(t_game *game);
void	error_message(t_game *game, int player_count,
			int exit_count, int collectible_count);
void	validate_walls_and_rectangle(t_game *game);
void	count_map_elements(t_game *game,
			int *player_count, int *exit_count, int *collectible_count);
int		is_valid_move(t_game *game, int new_x, int new_y);
void	handle_tile_interaction(t_game *game, int new_x, int new_y);
void	update_player_position(t_game *game, int new_x, int new_y);
void	validate_valid_char(char tile, t_game *game);

//Verif map finissable
char	**clone_map(t_game *game);
void	free_clone(t_game *game, int rows);
void	flood_fill(t_game *game, int x, int y);
void	check_reachability(t_game *game);
void	validate_playable_map(t_game *game);
void	check_unreachable_collectibles(t_game *game,
			char **map, int rows, int cols);
void	check_unreachable_exit(t_game *game, char **map,
			int rows, int cols);

//Quitter le jeu
void	exit_game(t_game *game);
void	exit_map(t_game *game);
int		on_destroy_bouton(t_game *game);
void	destroy_images(t_game *game);
void	destroy_window_and_mlx(t_game *game);

#endif