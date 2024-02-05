/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:10:57 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/10 14:08:59 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	name_map(char *arg)
{
	char	*v_arg;

	if (!ft_strrchr(arg, '.'))
		return (0);
	else
	{
		v_arg = ft_strrchr(arg, '.');
		if (ft_strlen(v_arg) != 4)
			return (0);
		if (v_arg[0] == '.' && v_arg[1] == 'b'
			&& v_arg[2] == 'e' && v_arg[3] == 'r')
			return (1);
	}
	return (0);
}

int	get_map(int fd, t_game *game, int error_count)
{
	char	*tmp_buf;
	char	*tmp_map;

	tmp_buf = get_next_line(fd);
	if (!tmp_buf)
		return (0);
	tmp_map = ft_strdup("");
	if (!tmp_map)
		return (0);
	while (tmp_buf != NULL)
	{
		tmp_map = strjoin(tmp_map, tmp_buf);
		if (tmp_buf[0] == '\n')
			error_count = 1;
		free(tmp_buf);
		tmp_buf = get_next_line(fd);
	}
	game->maps.map = ft_split(tmp_map, '\n');
	free(tmp_map);
	free(tmp_buf);
	if (error_count == 1)
		return (free_map(game), 0);
	if (!game->maps.map)
		return (0);
	return (1);
}

int	verif_wall(char **map, int max_x, int max_y)
{
	int	tmp_y;
	int	tmp_x;

	tmp_y = 0;
	tmp_x = 0;
	while (tmp_x < max_x)
	{
		if (map[0][tmp_x] != '1' || map[max_y][tmp_x] != '1')
			return (0);
		tmp_x++;
	}
	while (tmp_y < max_y)
	{
		if (map[tmp_y][0] != '1' || map[tmp_y][max_x - 1] != '1')
			return (0);
		tmp_y++;
	}
	return (1);
}

int	verif_start(t_game *game, int x, int y)
{
	while (game->maps.map[++y])
	{
		while (game->maps.map[y][x])
		{
			if (game->maps.map[y][x] == 'C')
				game->maps.item++;
			if (game->maps.map[y][x] == 'E')
			{
				game->maps.x_exit = x;
				game->maps.y_exit = y;
				game->maps.n_exit++;
			}
			if (game->maps.map[y][x] == 'P')
				game->maps.start++;
			if (game->maps.map[y][x] != '0' && game->maps.map[y][x] != '1'
				&& game->maps.map[y][x] != 'C' && game->maps.map[y][x] != 'E'
				&& game->maps.map[y][x] != 'P')
				return (0);
			x++;
		}
		x = 0;
	}
	if (game->maps.item == 0 || game->maps.n_exit == 0 || game->maps.start == 0)
		return (0);
	return (1);
}

int	verif_map(t_game *game)
{
	int	max_x;
	int	max_y;
	int	tmp_x;

	max_x = 0;
	max_y = 0;
	tmp_x = 0;
	while (game->maps.map[max_y][tmp_x])
	{
		tmp_x = ft_strlen(game->maps.map[max_y]);
		if (max_y == 0)
			max_x = tmp_x;
		else if (tmp_x != max_x)
			return (0);
		tmp_x = 0;
		if (!game->maps.map[max_y + 1])
			break ;
		max_y++;
	}
	if (!verif_wall(game->maps.map, max_x, max_y)
		|| !verif_start(game, 0, -1))
		return (0);
	game->maps.x = max_x;
	game->maps.y = max_y;
	return (1);
}
