/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:07:26 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/08 20:39:30 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//cc error_map.c get_next_line.c get_next_line_utils.c so_long.c printf/libftprintf.a -lX11 -lXext libmlx_Linux.a

#ifndef SO_LONG_H
# define SO_LONG_H

# include "printf/ft_printf.h"
# include "get_next_line.h"
# include "minilibx-linux/mlx.h"

# define KeyESC 65307
# define KeyW 119
# define KeyA 97
# define KeyS 115
# define KeyD 100

typedef struct t_map
{
	int		x;
	int		y;
	int		emplyt;
	int		item;
	int		pdep;
	int		n_exit;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	char	**map;
}				s_map;

typedef struct	s_vars {
	void	*mlx;
	void	*mlx_win;
}				t_vars;

int	name_map(char *arg);
void	map(int fd, s_map *map);
int	verif_map(s_map *maps);
void	event_up(t_vars *vars, s_map *maps);
void	ft_img(void *mlx, void *win_ptr, char type, int x, int y);

#endif