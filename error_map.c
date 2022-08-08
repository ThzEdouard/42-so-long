/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:11:16 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/08 12:30:06 by eflaquet         ###   ########.fr       */
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
	tmp_y = 1;
	tmp_x = 0;

	while (map[0][tmp_x])
	{
		if (map[0][tmp_x] && map[0][tmp_x] != '1')
			return (0);
		tmp_x++;
	}
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
		max_y++;
	}
	if (max_x == max_y || !verif_wall(maps->map, max_x, max_y))
		return (0);
	return (1);
}
