/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:07:47 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/07 16:33:53 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 100

char	*get_next_line(int fd);
void	get_read_file(int fd, char **trash, int *byte_ptr);
char	*substr(char *s, unsigned int start, size_t len);
char	*get_save_trash(char *trash, int len_line);
char	*strjoin(char *s1, char *s2);
int		str_len(char *str);
int		ft_newline(char *str);
int		ft_lenline(char *str);

#endif
