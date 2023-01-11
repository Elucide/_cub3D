/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:00:26 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/11 19:14:49 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	store_map()
{
	t_data	*data;
	char	*tmp_join;
	char	*tmp;
	int		i;

	data = _data();
	tmp_join = NULL;
	while(1)
	{
		i = 0;
		tmp = get_next_line(data->fd);
		while (tmp[i] && is_space(tmp[i]))
			i++;
		if (!tmp[i])
			break;
	}
	while(tmp != NULL)
	{
		tmp_join = ft_strjoin(tmp_join, tmp);
		tmp = get_next_line(data->fd);
	}
	data->map = split_map(tmp_join, '\n');
}

int	is_map_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E'
			|| is_space(c))
		return (1);
	return (0);
}

void	check_map()
{
	int	i;
	int	j;
	int	empty;
	t_data	*data;

	data = _data();
	i = 0;
	j = 0;
	empty = 0;
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if (j == 0)
			{
				while(is_space(data->map[i][j]))
					j++;
				if (!data->map[i][j])
					empty++;
			}
			if (!is_map_char(data->map[i][j]) || (is_map_char(data->map[i][j]) && empty))
			{
				printf("Error\nInvalid character in map\n");
				free_garbage();
			}
			j++;
		}
		i++;
	}
}

int		max_map(void)
{	
	t_data	*data;
	int		i;

	data = _data();
	i = 0;
	while(data->map[i])	
		i++;
	return (i - 1);
}


void	is_map_closed(void)
{
	int	i;
	int	j;
	t_data	*data;

	data = _data();
	i = 0;
	j = 0;
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
					if (i != 0 && j != 0 && j != ft_strlen(data->map[i])
						&& i != max_map())
					{
					if (j+1 == ft_strlen(data->map[i]) || j >= ft_strlen(data->map[i - 1]) 
						|| j >= ft_strlen(data->map[i + 1]) || data->map[i - 1][j] == ' '
						|| data->map[i + 1][j] == ' ' || data->map[i][j - 1] == ' '
						|| data->map[i][j + 1] == ' ')
						{	
							printf("Error\nMap not closed\n");
							free_garbage();
						}
					}
					else
					{	
						printf("Error\nMap not closed\n");
						free_garbage();
					}

			}
			j++;
		}
		i++;
	}
}

void	parse_map(void)
{
	t_data	*data;

	data = _data();
	if (data->fd > 0)
	{
		store_map();
		check_map();
		is_map_closed();

		close(data->fd);
	}
}
