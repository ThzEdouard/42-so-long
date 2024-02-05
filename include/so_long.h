/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:43:50 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/10 11:24:13 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../printf/ft_printf.h"
# include "../printf/libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define KEYESC 65307
# define KEYW 119
# define KEYA 97
# define KEYS 115
# define KEYD 100

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
}				t_vars;

typedef struct s_map
{
	char		**map;
	int			x;
	int			y;
	int			item;
	int			emplity;
	int			start;
	int			n_exit;
	int			x_exit;
	int			y_exit;
}				t_map;

typedef struct s_img
{
	void		*exitimg;
	void		*item_one;
	void		*item_two;
	void		*player;
	void		*sole;
	void		*wall;
}				t_img;

typedef struct s_game
{
	int			count;
	t_player	player;
	t_vars		vars;
	t_map		maps;
	t_img		img;
}				t_game;

int		name_map(char *arg);
int		get_map(int fd, t_game *game, int count);
int		verif_map(t_game *game);
void	creating_windows_mlx(t_game *game);
void	ft_printf_img(t_game *game, void *img, int x, int y);
void	free_map(t_game *game);
int		end_game(t_game *game);
int		img_set(t_game *game);
void	event_up(t_game *game);
void	event_down(t_game *game);
void	event_left(t_game *game);
void	event_right(t_game *game);
void	creating_backgrond(t_game *game);
void	creating_option(t_game *game, int x, int y);
void	creating_map(t_game *game);
void	string_put(t_game *game);
void	end_player(t_game *game);
void	init(t_game *game);

#endif