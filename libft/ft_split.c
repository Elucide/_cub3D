/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:55:06 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/03 19:14:52 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char *str, char charset)
{
	if (*str == charset)
		return (1);
	return (0);
}

static int	ft_letter_count(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(ft_is_sep(str + i, charset)))
		i++;
	return (i);
}

static int	word_count(char *str, char charset)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		if (*str && ft_is_sep(str, charset))
			str++;
		i = ft_letter_count(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

static char	*word_cpy(char *str, int size)
{
	char	*dest;

	dest = ft_malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	dest[size] = '\0';
	while (size--)
		dest[size] = str[size];
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		i;
	int		size;
	int		j;

	i = 0;
	size = word_count((char *)s, c);
	matrix = ft_malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		while (*s && ft_is_sep((char *)s, c))
			s++;
		j = ft_letter_count((char *)s, c);
		matrix[i] = word_cpy((char *)s, j);
		if (matrix[i] == NULL)
			return (NULL);
		s += j;
		i++;
	}
	matrix[size] = 0;
	return (matrix);
}
