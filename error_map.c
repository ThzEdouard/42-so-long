/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:11:16 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/08 16:31:17 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	name_map(char *arg)
{
	char	*v_arg;

	if (!ft_strrchr(arg, '.'))
		return (0);
	else
	{
		v_arg =  ft_strrchr(arg, '.');
		if (ft_strlen(v_arg) != 4)
			return (0);
		if (v_arg[0] == '.' && v_arg[1] == 'b' && v_arg[2] == 'e' && v_arg[3] == 'r')
			return (1);
	}
	return (0);
}

void	map(int fd, s_map *maps)
{
	char	*tmp_buf;
	char	*tmp_map;

	tmp_buf = get_next_line(fd);
	tmp_map = ft_strdup("");
	while (tmp_buf != NULL)
	{
		tmp_map = strjoin(tmp_map, tmp_buf);
		free(tmp_buf);
		tmp_buf = get_next_line(fd);
	}
	maps->map = ft_split(tmp_map, '\n');
	free(tmp_map);
	free(tmp_buf);
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

int	verif_start(s_map *maps)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (maps->map[y])
	{
		while (maps->map[y][x])
		{
			if (maps->map[y][x] == 'C')
				maps->item++;
			if (maps->map[y][x] == 'E')
				maps->n_exit++;
			if (maps->map[y][x] == 'P')
				maps->pdep++;
			if (maps->map[y][x] != '0' && maps->map[y][x] != '1' && maps->map[y][x] != 'C' && maps->map[y][x] != 'E' && maps->map[y][x] != 'P')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	if (maps->item == 0 || maps->n_exit == 0 || maps->pdep == 0)
		return (0);
	return (1);
}

int	verif_map(s_map *maps)
{
	int	max_x;
	int	max_y;
	int	tmp_x;

	max_x = 0;
	max_y = 0;
	if (!maps->map)
		return (0);
	while (maps->map[max_y][tmp_x])
	{
		tmp_x = ft_strlen(maps->map[max_y]);

		if (max_y == 0)
			max_x = tmp_x;
		else if (tmp_x != max_x)
			return (0);
		tmp_x = 0;
		if (!maps->map[max_y + 1])
			break ;
		max_y++;
	}
	if (max_x == max_y || !verif_wall(maps->map, max_x, max_y) || !verif_start(maps))
		return (0);
	maps->x = max_x;
	maps->y = max_y;
	return (1);
}
