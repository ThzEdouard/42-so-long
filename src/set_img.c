/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:50:49 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/10 10:39:32 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	set_img_one(t_game *game, int img_height, int img_width)
{
	game->img.wall = mlx_xpm_file_to_image(game->vars.mlx,
			"img_map/wall.xpm", &img_width, &img_height);
	if (!game->img.wall)
		return (0);
	game->img.sole = mlx_xpm_file_to_image(game->vars.mlx,
			"img_map/sole.xpm", &img_width, &img_height);
	if (!game->img.sole)
	{
		mlx_destroy_image(game->vars.mlx, game->img.wall);
		return (0);
	}
	game->img.player = mlx_xpm_file_to_image(game->vars.mlx,
			"img_map/player.xpm", &img_width, &img_height);
	if (!game->img.player)
	{
		mlx_destroy_image(game->vars.mlx, game->img.wall);
		mlx_destroy_image(game->vars.mlx, game->img.sole);
		return (0);
	}
	return (1);
}

int	set_img_two(t_game *game, int img_height, int img_width)
{
	game->img.item_one = mlx_xpm_file_to_image(game->vars.mlx,
			"img_map/item-1.xpm", &img_width, &img_height);
	if (!game->img.item_one)
	{
		mlx_destroy_image(game->vars.mlx, game->img.wall);
		mlx_destroy_image(game->vars.mlx, game->img.sole);
		mlx_destroy_image(game->vars.mlx, game->img.player);
		return (0);
	}
	game->img.item_two = mlx_xpm_file_to_image(game->vars.mlx,
			"img_map/item-2.xpm", &img_width, &img_height);
	if (!game->img.item_two)
	{
		mlx_destroy_image(game->vars.mlx, game->img.wall);
		mlx_destroy_image(game->vars.mlx, game->img.sole);
		mlx_destroy_image(game->vars.mlx, game->img.player);
		mlx_destroy_image(game->vars.mlx, game->img.item_one);
		return (0);
	}
	return (1);
}

int	set_img_tree(t_game *game, int img_height, int img_width)
{
	game->img.exitimg = mlx_xpm_file_to_image(game->vars.mlx,
			"img_map/exit-img.xpm", &img_width, &img_height);
	if (!game->img.exitimg)
	{
		mlx_destroy_image(game->vars.mlx, game->img.wall);
		mlx_destroy_image(game->vars.mlx, game->img.sole);
		mlx_destroy_image(game->vars.mlx, game->img.player);
		mlx_destroy_image(game->vars.mlx, game->img.item_one);
		mlx_destroy_image(game->vars.mlx, game->img.item_two);
		return (0);
	}
	return (1);
}

int	img_set(t_game *game)
{
	int	img_height;
	int	img_width;

	img_height = 0;
	img_width = 0;
	if (set_img_one(game, img_height, img_width)
		&& set_img_two(game, img_height, img_width)
		&& set_img_tree(game, img_height, img_width))
		return (1);
	return (0);
}

void	ft_printf_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->vars.mlx,
		game->vars.mlx_win, img, x * 64, y * 64);
}
