/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:52:52 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/10 14:01:20 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	end_player(t_game *game)
{
	if (game->maps.item == 0
		&& game->player.x == game->maps.x_exit
		&& game->player.y == game->maps.y_exit)
		end_game(game);
}

void	event_up(t_game *game)
{
	int	count;

	count = 0;
	if (game->maps.map[game->player.y - 1][game->player.x] == '1')
		return ;
	if (game->maps.map[game->player.y - 1][game->player.x] == 'C')
	{
		if (--game->maps.item == 0)
			count = 1;
	}
	else if (game->maps.item == 0
		&& game->maps.map[game->player.y - 1][game->player.x] == 'E')
		ft_printf("Game finish to %d count\n", ++game->count);
	game->maps.map[game->player.y - 1][game->player.x] = 'P';
	if (count == 1)
	{
		game->maps.map[game->player.y][game->player.x] = '0';
		game->maps.map[game->maps.y_exit][game->maps.x_exit] = 'E';
	}
	else
		game->maps.map[game->player.y][game->player.x] = '0';
	game->player.y--;
	creating_map(game);
	game->count++;
	string_put(game);
}

void	event_down(t_game *game)
{
	int	count;

	count = 0;
	if (game->maps.map[game->player.y + 1][game->player.x] == '1')
		return ;
	if (game->maps.map[game->player.y + 1][game->player.x] == 'C')
	{
		if (--game->maps.item == 0)
			count = 1;
	}
	else if (game->maps.item == 0
		&& game->maps.map[game->player.y + 1][game->player.x] == 'E')
		ft_printf("Game finish to %d count\n", ++game->count);
	game->maps.map[game->player.y + 1][game->player.x] = 'P';
	if (count == 1)
	{
		game->maps.map[game->player.y][game->player.x] = '0';
		game->maps.map[game->maps.y_exit][game->maps.x_exit] = 'E';
	}
	else
		game->maps.map[game->player.y][game->player.x] = '0';
	game->player.y++;
	creating_map(game);
	game->count++;
	string_put(game);
}

void	event_left(t_game *game)
{
	int	count;

	count = 0;
	if (game->maps.map[game->player.y][game->player.x - 1] == '1')
		return ;
	if (game->maps.map[game->player.y][game->player.x - 1] == 'C')
	{
		if (--game->maps.item == 0)
			count = 1;
	}
	else if (game->maps.item == 0
		&& game->maps.map[game->player.y][game->player.x - 1] == 'E')
		ft_printf("Game finish to %d count\n", ++game->count);
	game->maps.map[game->player.y][game->player.x - 1] = 'P';
	if (count == 1)
	{
		game->maps.map[game->player.y][game->player.x] = '0';
		game->maps.map[game->maps.y_exit][game->maps.x_exit] = 'E';
	}
	else
		game->maps.map[game->player.y][game->player.x] = '0';
	game->player.x--;
	creating_map(game);
	game->count++;
	string_put(game);
}

void	event_right(t_game *game)
{
	int	count;

	count = 0;
	if (game->maps.map[game->player.y][game->player.x + 1] == '1')
		return ;
	if (game->maps.map[game->player.y][game->player.x + 1] == 'C')
	{
		if (--game->maps.item == 0)
			count = 1;
	}
	else if (game->maps.item == 0
		&& game->maps.map[game->player.y][game->player.x + 1] == 'E')
		ft_printf("Game finish to %d count\n", ++game->count);
	game->maps.map[game->player.y][game->player.x + 1] = 'P';
	if (count == 1)
	{
		game->maps.map[game->player.y][game->player.x] = '0';
		game->maps.map[game->maps.y_exit][game->maps.x_exit] = 'E';
	}
	else
		game->maps.map[game->player.y][game->player.x] = '0';
	game->player.x++;
	creating_map(game);
	game->count++;
	string_put(game);
}
