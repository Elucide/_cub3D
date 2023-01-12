/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:25:56 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/12 23:37:15 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*format_split(char *s)
{
	int		i;

	while (1)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '\n')
				break ;
			if (is_space(s[i]))
				i++;
			else
				break ;
		}
		if (s[i] == '\n')
		{
			while (i >= 0)
			{
				s++;
				i--;
			}
		}
		else
			return (s);
	}
}

void	print_error(char *s)
{
	printf("%s", s);
	free_garbage();
}

void	check_digit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				print_error("Error\nInvalid declaration\n");
			j++;
		}
		i++;
	}
}

int	max_map(void)
{	
	t_data	*data;
	int		i;

	data = _data();
	i = 0;
	while (data->map[i])
		i++;
	return (i - 1);
}
