/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:48:01 by eflaquet          #+#    #+#             */
/*   Updated: 2022/07/08 07:55:56 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char c, va_list l)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(l, int));
	else if (c == 's')
		i += ft_putstr(va_arg(l, char *));
	else if (c == 'p')
		i += ft_put_padress(va_arg(l, void *), "0123456789abcdef", 0);
	else if (c == 'd')
		i += ft_putnbr_len(va_arg(l, int));
	else if (c == 'i')
		i += ft_putnbr_len(va_arg(l, int));
	else if (c == 'u')
		i += ft_putnbr_u((unsigned int)va_arg(l, unsigned int));
	else if (c == 'x')
		i += ft_puthex(va_arg(l, int), "0123456789abcdef");
	else if (c == 'X')
		i += ft_puthex(va_arg(l, int), "0123456789ABCDEF");
	else if (c == '%')
		i += ft_putchar('%');
	else
		i += ft_printf("%%%c", c);
	return (i);
}

int	ft_printf(const char *f, ...)
{
	va_list	list;
	int		rest;
	int		i;

	rest = 0;
	i = 0;
	va_start(list, f);
	while (f[i])
	{
		if (f[i] == '%')
		{
			if (f[i + 1] != 0)
			{
				rest += check_format(f[i + 1], list);
				i++;
			}
		}
		else
			rest += ft_putchar(f[i]);
		i++;
	}
	va_end(list);
	return (rest);
}
