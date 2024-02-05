/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:12:56 by eflaquet          #+#    #+#             */
/*   Updated: 2022/07/08 07:55:56 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_count_word(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] != '\0' && (s[i] == c))
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && !(s[i] == c))
			i++;
	}
	return (count);
}

void	ft_input(char **tabs, char *str, char c, int i)
{
	int	cs;
	int	co;
	int	y;

	y = 0;
	while (str[i])
	{
		cs = i;
		co = 0;
		while (str[cs] && !(str[cs++] == c))
			co++;
		if (co)
		{
			cs = 0;
			tabs[y] = malloc(sizeof(char) * (co + 1));
			while (str[i] && !(str[i] == c))
				tabs[y][cs++] = str[i++];
			tabs[y][cs] = '\0';
			y++;
		}
		if (str[i])
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (ft_count_word((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	ft_input(tab, (char *)s, c, 0);
	tab[ft_count_word((char *)s, c)] = 0;
	return (tab);
}
