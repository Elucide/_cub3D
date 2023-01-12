/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:30:48 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/12 23:04:21 by rbenayou         ###   ########.fr       */
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
			print_error("Error\nInvalid declaration\n");
		i++;
	}
	return (tmp);
}

int	coma_count(char *s)
{
	int		coma;
	int		i;

	coma = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ',')
			coma++;
		i++;
	}
	return (coma);
}

int	parse_color(char *s)
{
	int		i;
	char	**tmp;

	if (!s)
		print_error("Error\nInvalid declaration\n");
	if (coma_count(s) == 2)
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
	print_error("Error\nInvalid declaration\n");
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
	else
		print_error("Error\nInvalid declaration\n");
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
		if (data->nb_el == 6)
			break ;
		tmp = get_next_line(data->fd);
		if (tmp == NULL)
			print_error("Error\nNo map in file\n");
		if (!check_line(tmp))
			break ;
	}
	if (data->nb_el != 6)
		print_error("Error\nToo few elements\n");
}
