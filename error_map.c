/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:11:16 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/07 18:41:20 by eflaquet         ###   ########.fr       */
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

int	verif_map(int fd)
{
	s_map	map;
	int x;
	while (map.map = get_next_line(fd))
	{
		map.y++;
		if (map.x == 0 || map.x != 0)
		{
			map.x = ft_strlen(map.map);
			x = map.x;
			if (x == ft_strlen(map.map))
				map.x = ft_strlen(map.map);
			else
				return (0);
			ft_printf("1");
		}
		if (verif_line(&map))
		{
			free(map.map);
			ft_printf("2");
		}else
		{
			free(map.map);
			ft_printf("3");
			return (0);
		}
		free(map.map);
	}
	if (map.x == map.y || map.y == 1 || map.x == 1)
		return (0);
	return (1);
}

int verif_line(s_map *map)
{
	static int	i = 0;
	int			x;

	if (i == 0)
{
		x = 0;
		while (map->map[x])
		{
			if (x < map->x && map->map[x] == '1')
			{
				x++;
				ft_printf("%c", map->map[x]);
			}
			else
				return (0);
		}
		i++;
		ft_printf(" 1.1");
	}
	else
		if (!verif_wall(map))
			return(0);
	return (1);
}

int	verif_wall(s_map *map)
{
	int	i;

	if (map->map[0] != '1' || map->map[map->x] != '1')
		return (0);
	i = 0;
	while (map->map[i])
	{
		if (map->map[i] != '1' || map->map[i] != '0' || map->map[i] != 'C'
			|| map->map[i] != 'E' || map->map[i] != 'P')
			return (0);
		if (map->map[i] != 'C')
			map->item++;
		if (map->map[i] != 'E')
			map->n_exit++;
		if ( map->map[i] != 'P')
			map->pdep++;
	}
	if (map->item >= 1 && map->n_exit >= 1 && map->pdep >= 1)
		return (1);
	return (0);
}