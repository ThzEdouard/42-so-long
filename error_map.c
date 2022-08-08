/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:11:16 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/08 11:36:55 by eflaquet         ###   ########.fr       */
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

int	verif_map(s_map *maps)
{
	
}