/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:20:29 by tlize             #+#    #+#             */
/*   Updated: 2025/04/13 16:21:17 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		exit_game(game);
	if (keycode == XK_w)
		move_player(game, 0, -1);
	else if (keycode == XK_s)
		move_player(game, 0, 1);
	else if (keycode == XK_a)
		move_player(game, -1, 0);
	else if (keycode == XK_d)
		move_player(game, 1, 0);
	return (0);
}

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->cols || new_y < 0 || new_y >= game->rows)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	handle_tile_interaction(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
		game->collectibles--;
	if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
	{
		ft_printf("Vous avez reussi en %d mouvements\n", game->move_count);
		exit_game(game);
	}
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	ft_printf("Mouvement numero : %d\n", game->move_count);
	game->map[new_y][new_x] = 'P';
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	handle_tile_interaction(game, new_x, new_y);
	if (game->map[new_y][new_x] == 'E')
		return ;
	update_player_position(game, new_x, new_y);
	draw_map(game);
}
