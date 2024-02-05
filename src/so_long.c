/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:44:00 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/10 14:11:09 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	next_main_two(char **argv, int fd, t_game *game)
{
	fd = open(argv[1], O_RDONLY);
	if (get_map(fd, game, 0))
	{
		if (verif_map(game))
			return (1);
		else
		{
			ft_printf("Error\nmap obsolete !\n");
			return (0);
		}
	}
	else
	{
		ft_printf("Error\nopen the map !\n");
		return (0);
	}
	return (1);
}

int	next_main(char **argv, int fd, t_game *game)
{
	if (name_map(argv[1]))
	{
		if (!next_main_two(argv, fd, game))
		{
			close(fd);
			return (0);
		}
		close(fd);
	}
	else
	{
		ft_printf("Error\nuse ./so_long [map.ber] !\n");
		return (0);
	}
	return (1);
}

int	end_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->maps.map != NULL)
	{
		while (game->maps.map[i] != NULL)
		{
			free(game->maps.map[i]);
			i++;
		}
		free(game->maps.map);
		mlx_destroy_image(game->vars.mlx, game->img.wall);
		mlx_destroy_image(game->vars.mlx, game->img.sole);
		mlx_destroy_image(game->vars.mlx, game->img.player);
		mlx_destroy_image(game->vars.mlx, game->img.item_one);
		mlx_destroy_image(game->vars.mlx, game->img.item_two);
		mlx_destroy_image(game->vars.mlx, game->img.exitimg);
		mlx_destroy_window(game->vars.mlx, game->vars.mlx_win);
	}
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	fd = 0;
	if (argc != 2)
	{
		ft_printf("Error\nuse ./so_long [map.ber] !\n");
	}
	else
	{
		init(&game);
		if (next_main(argv, fd, &game))
		{
			creating_windows_mlx(&game);
		}
		free_map(&game);
	}
	return (0);
}
