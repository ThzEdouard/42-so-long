/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:08:27 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/07 17:40:49 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (name_map(argv[1]))
		{
			//ft_printf("%s nice name", argv[1]) ;
			int fd = open(argv[1], O_RDONLY);
			if (verif_map(fd))
				ft_printf("map ok");
			else
				ft_printf("non");
		}
		else
			ft_printf("non");
	}

}