/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:07:26 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/07 16:35:42 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "printf/ft_printf.h"
# include "get_next_line.h"

typedef struct t_map
{
	int	x;
	int	y;
	int	emplyt;
	int	item;
	int	pdep;
	int n_exit;
	char	*map;
}				s_map;

int	name_map(char *arg);
int	verif_map(int fd);

#endif