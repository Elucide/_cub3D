/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:30:48 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/06 18:36:33 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*check_element(char *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (s[i] && is_space(s[i]))
		i++;
	if (!s[i])
		return (NULL);
	while (s[i] && !is_space(s[i]))
	{
		j++;
		i++;
	}
	tmp = ft_substr(s, i - j, j);
	while (s[i] && is_space(s[i]))
	{
		if (s[i + 1] && is_space(s[i]) && !is_space(s[i + 1]))
		{
			printf("Error\nInvalid declaration\n");
			free_garbage();
		}
		i++;
	}
	return (tmp);
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
			{
				printf("Error\nInvalid declaration\n");
				free_garbage();
			}
			j++;
		}
		i++;
	}
}

int	parse_color(char *s)
{
	int		coma;
	int		i;
	char	**tmp;

	i = 0;
	coma = 0;
	while (s[i])
	{
		if (s[i] == ',')
			coma++;
		i++;
	}
	if (coma == 2)
	{
		tmp = ft_split(s, ',');
		i = 0;
		check_digit(tmp);
		while (tmp[i])
		{
			if (ft_atoi(tmp[i]) >= 0 && ft_atoi(tmp[i]) <= 255)
				i++;
			else
				break ;
		}
		if (i == 3)
			return (rgb_convert(ft_atoi(tmp[0]), ft_atoi(tmp[1])
					, ft_atoi(tmp[2])));
	}
	printf("Error\nInvalid declaration\n");
	free_garbage();
	return (1);
}


int	check_line(char *tmp)
{
	t_data	*data;

	data = _data();
	while (tmp[0] && is_space(tmp[0]))
		tmp++;
	if (!tmp[0])
		return (1);
	if (!ft_strncmp(tmp, "NO", 2) && is_space(tmp[2]))
		data->no = store_element(data->no, tmp);
	else if (!ft_strncmp(tmp, "SO", 2) && is_space(tmp[2]))
		data->so = store_element(data->so, tmp);
	else if (!ft_strncmp(tmp, "WE", 2) && is_space(tmp[2]))
		data->we = store_element(data->we, tmp);
	else if (!ft_strncmp(tmp, "EA", 2) && is_space(tmp[2]))
		data->ea = store_element(data->ea, tmp);
	else if (!ft_strncmp(tmp, "F", 1) && is_space(tmp[1]))
		data->floor = store_color(data->floor, tmp);
	else if (!ft_strncmp(tmp, "C", 1) && is_space(tmp[1]))
		data->ceiling = store_color(data->ceiling, tmp);
	else if (tmp[0] == '1' || tmp[0] == '0' || tmp[0] == 'N'
		|| tmp[0] == 'S' || tmp[0] == 'E' || tmp[0] == 'W')
		return (0);
	else
	{
		printf("Error\nInvalid declaration\n");
		free_garbage();
	}
	return (1);
}

void	parse_elements(void)
{
	t_data	*data;
	char	*tmp;

	data = _data();
	data->nb_el = 0;
	while (1)
	{
		tmp = get_next_line(data->fd);
		if (tmp == NULL)
			break ;
		if (!check_line(tmp))
			break ;
		close(data->fd);
	}
	if (data->nb_el != 6)
	{
		printf("Error\nToo few elements\n");
		free_garbage();
	}
}

