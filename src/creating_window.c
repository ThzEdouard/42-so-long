/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:28:59 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/10 10:40:01 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	creating_backgrond(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->maps.map[y] != NULL)
	{
		x = 0;
		while (game->maps.map[y][x] != '\0')
		{
			if (game->maps.map[y][x] == '1')
				ft_printf_img(game, game->img.wall, x, y);
			if (game->maps.map[y][x] == '0'
				|| (game->maps.item != 0 && game->maps.map[y][x] == 'E'))
				ft_printf_img(game, game->img.sole, x, y);
			x++;
		}
		y++;
	}
}

void	creating_option(t_game *game, int x, int y)
{
	while (game->maps.map[y] != NULL)
	{
		x = 0;
		while (game->maps.map[y][x] != '\0')
		{
			if (game->maps.map[y][x] == 'P')
			{
				ft_printf_img(game, game->img.player, x, y);
				game->player.x = x;
				game->player.y = y;
			}
			if (game->maps.map[y][x] == 'C' && x % 2 == 0)
				ft_printf_img(game, game->img.item_one, x, y);
			else if (game->maps.map[y][x] == 'C' && x % 2 != 0)
				ft_printf_img(game, game->img.item_two, x, y);
			if (game->maps.item == 0
				&& game->maps.map[game->maps.y_exit][game->maps.x_exit] == 'E')
				ft_printf_img(game, game->img.exitimg,
					game->maps.x_exit, game->maps.y_exit);
			x++;
		}
		y++;
	}
}

int	event_key(int keycode, t_game *game)
{
	if (keycode == KEYESC)
	{
		end_game(game);
	}
	if (keycode == KEYW)
		event_up(game);
	if (keycode == KEYS)
		event_down(game);
	if (keycode == KEYA)
		event_left(game);
	if (keycode == KEYD)
		event_right(game);
	return (0);
}

void	creating_map(t_game *game)
{
	creating_backgrond(game);
	creating_option(game, 0, 0);
}

void	creating_windows_mlx(t_game *game)
{
	game->vars.mlx = mlx_init();
	if (!game->vars.mlx)
		return ;
	game->vars.mlx_win = mlx_new_window(game->vars.mlx, game->maps.x * 64,
			(game->maps.y + 1) * 64, "so_long");
	if (!game->vars.mlx_win)
	{
		mlx_destroy_display(game->vars.mlx);
		free(game->vars.mlx);
		exit(0);
		return ;
	}
	if (!img_set(game))
	{
		free_map(game);
		mlx_destroy_window(game->vars.mlx, game->vars.mlx_win);
		mlx_destroy_display(game->vars.mlx);
		free(game->vars.mlx);
		exit(0);
	}
	creating_map(game);
	mlx_key_hook(game->vars.mlx_win, event_key, game);
	mlx_hook(game->vars.mlx_win, 17, 0, &end_game, game);
	mlx_loop(game->vars.mlx);
}
