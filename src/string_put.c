/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:44:34 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/10 14:12:46 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	string_put(t_game *game)
{
	char	*string;

	end_player(game);
	ft_printf("%d\n", game->count);
	string = ft_itoa(game->count);
	if (!string)
		return ;
	mlx_string_put(game->vars.mlx, game->vars.mlx_win, 30, 36, 0xFFF, string);
	free(string);
}

void	init(t_game *game)
{
	game->count = 0;
	game->maps.map = NULL;
	game->maps.emplity = 0;
	game->maps.item = 0;
	game->maps.start = 0;
	game->maps.n_exit = 0;
}

void	free_map(t_game *game)
{
	int	y;

	y = 0;
	if (!game->maps.map)
		return ;
	while (game->maps.map[y] != NULL)
	{
		free(game->maps.map[y]);
		y++;
	}
	free(game->maps.map);
}
