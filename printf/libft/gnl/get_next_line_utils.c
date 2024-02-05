/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:09:45 by eflaquet          #+#    #+#             */
/*   Updated: 2022/08/07 16:33:43 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_lenline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[0] == '\n')
		return (1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int	ft_newline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*strjoin(char *s1, char *s2)
{
	char	*dest;
	int		size;
	int		i;
	int		j;

	size = str_len(s1) + str_len(s2);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest || !s1 || !s2)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[size] = 0;
	free(s1);
	return (dest);
}

char	*substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	j = 0;
	if (!s)
		return (NULL);
	i = str_len(s);
	if (start > i)
		start = i;
	if (len > i - start)
		len = i - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (j < len && start + j <= i && s[start + j])
	{
		ptr[j] = s[start + j];
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}
