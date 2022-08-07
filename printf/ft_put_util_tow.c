/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_util_tow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:47:46 by eflaquet          #+#    #+#             */
/*   Updated: 2022/07/08 07:55:56 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int o, char *base)
{
	unsigned int	i;
	unsigned int	tmp;

	i = 0;
	tmp = o;
	if (tmp < 16)
		i += ft_putchar(base[tmp]);
	else
	{
		i += ft_puthex(tmp / 16, base);
		i += ft_puthex(tmp % 16, base);
	}
	return (i);
}

int	ft_put_padress(void const *p, char const *base, int s)
{
	unsigned long	adr;
	int				x;

	x = 0;
	if (!p && s != 1)
		return (ft_putstr("(nil)"));
	adr = (unsigned long) p;
	if (!s)
		x += ft_putstr("0x");
	if (adr < 16)
		x += ft_putchar(base[adr]);
	else
	{
		x += ft_put_padress((const void *)((unsigned long)p / 16), base, 1);
		x += ft_put_padress((const void *)((unsigned long)p % 16), base, 1);
	}
	return (x);
}
