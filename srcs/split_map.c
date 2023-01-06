/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:55:06 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/06 22:05:36 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

char	**split_map(char const *s, char c)
{
	char	**matrix;
	int		i;
	int		size;
	int		j;

	size = word_count((char *)s, c);
	matrix = ft_malloc(sizeof(char *) * (size + 1));
	while (1)
	{
		i = 0;
		while (s[i])
		{
			//printf("ok%d ='%c'\n", i, s[i]);
			if (s[i] == '\n')
				break ;
			if (is_space(s[i]))
				i++;
			else
				break;
		}
		if (s[i] == '\n')
		{
			while(i >= 0)
			{
				s++;
				i--;
			}
		}
		else
			break ;
	}
	i = 0;
	while (i < size)
	{
		if (*s && ft_is_sep((char *)s, c))
			s++;
		if (*s && ft_is_sep((char *)s, c))
		{
			printf("Error\nEmpty line in map\n");
			free_garbage();
		}
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
