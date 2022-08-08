/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:52:10 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/08 20:48:50 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	event_up(t_vars *vars ,s_map *maps)
{
	if (maps->player_y - 1 == 0 /*|| maps->map[maps->player_y - 1][maps->player_x] == '1'*/)
		return ;
	ft_printf("%d", maps->player_y - 1);
	/*ft_img(vars->mlx, vars->mlx_win, '0',maps->player_x, maps->player_y);
	if (maps->map[maps->player_y - 1][maps->player_x] == 'C')
	{
		maps->item--;
		if (maps->item == 0)
			ft_img(vars->mlx, vars->mlx_win, 'E',maps->exit_x, maps->exit_y);
	}
	maps->player_y--;
	ft_img(vars->mlx, vars->mlx_win, 'P',maps->player_x, maps->player_y);*/
}