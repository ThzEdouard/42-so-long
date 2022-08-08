/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:08:27 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/08 20:53:42 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void	ft_img(void *mlx, void *win_ptr, char type, int x, int y)
{
	void	*img;
	int	img_width;
	int		img_height;

	if (type == '1')
	{
		img = mlx_xpm_file_to_image(mlx, "wall.xpm", &img_width, &img_height);
		mlx_put_image_to_window(mlx, win_ptr, img, x * 64, y * 64);
	}
	if (type == '0')
	{
		img = mlx_xpm_file_to_image(mlx, "sole.xpm", &img_width, &img_height);
		mlx_put_image_to_window(mlx, win_ptr, img, x * 64, y * 64);
	}
	if (type == 'C')
	{
		if (x % 2 == 0)
		{
			img = mlx_xpm_file_to_image(mlx, "item-1.xpm", &img_width, &img_height);
			mlx_put_image_to_window(mlx, win_ptr, img, x * 64, y * 64);
		}
		if (x % 2 != 0)
		{
			img = mlx_xpm_file_to_image(mlx, "item-2.xpm", &img_width, &img_height);
			mlx_put_image_to_window(mlx, win_ptr, img, x * 64, y * 64);
		}
	}
	if (type == 'P')
	{
		img = mlx_xpm_file_to_image(mlx, "player.xpm", &img_width, &img_height);
		mlx_put_image_to_window(mlx, win_ptr, img, x * 64, y * 64);
	}
	if (type == 'E')
	{
		img = mlx_xpm_file_to_image(mlx, "exit.xpm", &img_width, &img_height);
		mlx_put_image_to_window(mlx, win_ptr, img, x * 64, y * 64);
	}
}

int	close_win(int keycode, t_vars *vars, s_map *maps)
{
	if (keycode == KeyESC)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		//mlx_destroy_image(vars->mlx ,img);
		exit(0);
	}
	if (keycode == KeyW)
		event_up(vars,&maps);
	/*if (keycode == KeyA)
		event_left(maps);
	if(keycode == keyS)
		event_down(maps);
	if (keycode == keyD)
		event_right(maps);*/
	return (0);
}

void	map_free(s_map *maps)
{
	int	y;
	int	x;

	y = 0;
	while (maps->map[y])
	{
		free(maps->map[y]);
		y++;
	}
	free(maps->map);
}

void	creating_windows_mlx(s_map *maps)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return ;
	vars.mlx_win = mlx_new_window(vars.mlx, maps->x * 64, (maps->y + 1) * 64, "so_long");
	while (maps->y >= 0)
	{
		maps->x = ft_strlen(maps->map[maps->y]);
		maps->x--;
		while (maps->x >= 0)
		{
			if (maps->map[maps->y][maps->x] == 'P')
			{
				maps->player_x = maps->x;
				maps->player_y = maps->y;
			}
			if (maps->map[maps->y][maps->x] == 'E')
			{
				ft_img(vars.mlx, vars.mlx_win,'0', maps->x, maps->y);
				maps->exit_x = maps->x;
				maps->exit_y = maps->y;
			}else
				ft_img(vars.mlx, vars.mlx_win, maps->map[maps->y][maps->x], maps->x, maps->y);
			maps->x--;
		}
		maps->y--;
	}
	mlx_hook(vars.mlx_win, 2, 1L<<0, close_win, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	s_map	maps;
	if (argc == 2)
	{
		if (name_map(argv[1]))
		{
			//ft_printf("%s nice name", argv[1]) ;
			int fd = open(argv[1], O_RDONLY);
			map(fd, &maps);
			if (verif_map(&maps))
				creating_windows_mlx(&maps);
			else
				ft_printf("Error map !");
		}
		else
			ft_printf("Error name map !");
	}

}
