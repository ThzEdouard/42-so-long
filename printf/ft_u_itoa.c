/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:09:45 by eflaquet          #+#    #+#             */
/*   Updated: 2022/07/08 07:55:56 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen_u(unsigned int nb)
{
	int	result;

	result = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		result++;
		nb /= 10;
	}
	return (result);
}

char	*ft_u_itoa(unsigned int n)
{
	char	*result;
	int		count;

	count = ft_intlen_u(n);
	result = (char *)ft_calloc((count + 1), sizeof(char));
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	while (n)
	{
		result[--count] = (n % 10) + '0';
		n = n / 10;
	}
	return (result);
}
