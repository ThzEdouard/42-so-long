/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:08:27 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/08 15:52:36 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int	main(int argc, char **argv)
{
	s_map	maps;
	if (argc == 2)
	{
		if (name_map(argv[1]))
		{
			//ft_printf("%s nice name", argv[1]) ;
			int fd = open(argv[1], O_RDONLY);
			map(fd, &maps);
			if (verif_map(&maps))
				//windows mlx !
			else
				ft_printf("Error map !");
		}
		else
			ft_printf("Error name map !");
	}

}