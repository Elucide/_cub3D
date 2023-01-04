/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:00:10 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/04 17:27:26 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f' || c == ' ') 
		return (1);
	return (0);
}

int	check_extension(char *path)
{
 	if (!ft_strcmp(ft_strnstr(path, ".cub", ft_strlen(path)), ".cub"))	
		return(1);
	return(0);
}

char	*check_element(char *s)
{
	int	i;
	int	j;
	char	*tmp;

	i = 0;
	j = 0;
	while(s[i] && is_space(s[i]))
		i++;
	if (!s[i])
		return(NULL);
	while(s[i] && !is_space(s[i]))
	{
		j++;
		i++;
	}
	tmp = ft_substr(s, i - j, j);
	while(s[i] && is_space(s[i]))
	{
		if (s[i + 1] && is_space(s[i]) && !is_space(s[i + 1]))
			return(NULL);
		i++;
	}
	return(tmp);
}

char	*store_element(char *element, char *s)
{
	if (element != NULL)
	{
		printf("Error\nDouble declaration\n");
		free_garbage();
	}
	s += 2;
	s = check_element(s);
	if (s == NULL)
	{
		printf("Error\nInvalid declaration\n");
		free_garbage();
	}
	return (s);
}

char	*store_color(char *element, char *s)
{
	if (element != NULL)
	{
		printf("Error\nDouble declaration\n");
		free_garbage();
	}
	s += 1;
	s = check_element(s);
	if (s == NULL)
	{
		printf("Error\nInvalid declaration\n");
		free_garbage();
	}
	return(parse_color(s));
}

int	check_line(char *tmp)
{
	t_data	*data;

	data=_data();
	while (tmp[0] && is_space(tmp[0]))
		tmp++;
	if (!tmp[0])
		return(1);
	if (!ft_strncmp(tmp, "NO", 2) && is_space(tmp[2]))
		data->no = store_element(data->no, tmp);
	else if (!ft_strncmp(tmp, "SO", 2) && is_space(tmp[2]))
		data->so = store_element(data->so, tmp);
	else if (!ft_strncmp(tmp, "WE", 2) && is_space(tmp[2]))
		data->we = store_element(data->we, tmp);
	else if (!ft_strncmp(tmp, "EA", 2) && is_space(tmp[2]))
		data->ea = store_element(data->ea, tmp);
	else if (!ft_strncmp(tmp, "F", 1) && is_space(tmp[1]))
		data->floor = parse_color(data->floor, tmp);
	else if (!ft_strncmp(tmp, "C", 1) && is_space(tmp[1]))
		data->floor = parse_color(data->ceiling, tmp);
	else if (tmp[0] == '1' || tmp[0] == '0' || tmp[0] == 'N' || tmp[0] == 'S' || tmp[0] == 'E' || tmp[0] == 'W')
		return(0);
	return(1);
	
}

void	parse_elements(void)
{
	t_data	*data;
	char	*tmp;

	data=_data();
	while(1)
	{
		tmp = get_next_line(data->fd);
		if(tmp == NULL)
			break;
		if (!check_line(tmp))
			break;
	}
}

void 	parse(void)
{
	t_data *data;

	data=_data();
	data->path = check_element(data->path);
	if (data->path != NULL && check_extension(data->path))
	{
		data->fd = open(data->path, O_RDONLY);
		if (data->fd > 0)
		{
			parse_elements();
			printf("NO =%s\n",data->no);
			printf("SO =%s\n",data->so);
			printf("WE =%s\n",data->we);
			printf("EA =%s\n",data->ea);
			//parse_map();
			return;
		}
	}
	printf("Error\nInvalid path\n");
	exit(EXIT_FAILURE);
}
