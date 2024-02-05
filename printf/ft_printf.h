/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:44:41 by eflaquet          #+#    #+#             */
/*   Updated: 2022/07/08 07:55:56 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *f, ...);
int		check_format(char c, va_list l);
char	*ft_u_itoa(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_len(int d);
int		ft_putnbr_u(unsigned int d);
int		ft_puthex(unsigned int o, char *base);
int		ft_put_padress(void const *p, char const *base, int s);

#endif
