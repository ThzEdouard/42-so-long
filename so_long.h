/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:07:26 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/08 12:13:50 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "printf/ft_printf.h"
# include "get_next_line.h"

typedef struct t_map
{
	int		emplyt;
	int		item;
	int		pdep;
	int		n_exit;
	char	**map;
}				s_map;

int	name_map(char *arg);
void	map(int fd, s_map *map);
int	verif_map(s_map *maps);
#endif