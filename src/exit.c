/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:16:19 by tlize             #+#    #+#             */
/*   Updated: 2025/04/13 18:40:33 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy_bouton(t_game *game)
{
	exit_game(game);
	return (0);
}

void	exit_map(t_game *game)
{
	int	i;

	i = 0;
	ft_printf("Libération de la carte.\n");
	if (game->map)
	{
		while (i < game->rows)
		{
			if (game->map[i])
			{
				free(game->map[i]);
				game->map[i] = NULL;
			}
			i++;
		}
		free(game->map);
		game->map = NULL;
		ft_printf("Carte libérée.\n");
	}
}

void	destroy_images(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
}

void	destroy_window_and_mlx(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
		ft_printf("MiniLibX libérée.\n");
	}
}

void	exit_game(t_game *game)
{
	exit_map(game);
	destroy_images(game);
	destroy_window_and_mlx(game);
	ft_printf("Toutes les ressources libérées.\n");
	exit(0);
}