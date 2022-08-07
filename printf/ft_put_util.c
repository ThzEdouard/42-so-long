/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:18:25 by eflaquet          #+#    #+#             */
/*   Updated: 2022/07/08 07:55:56 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		i = 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		i = ft_strlen(s);
	}
	return (i);
}

int	ft_putnbr_len(int d)
{
	char	*s;
	int		i;

	s = ft_itoa(d);
	if (!s)
		return (0);
	ft_putstr_fd(s, 1);
	i = ft_strlen(s);
	free(s);
	return (i);
}

int	ft_putnbr_u(unsigned int d)
{
	char	*s;
	int		i;

	s = ft_u_itoa(d);
	if (!s)
		return (0);
	ft_putstr_fd(s, 1);
	i = ft_strlen(s);
	free(s);
	return (i);
}
