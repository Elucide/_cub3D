/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:00:26 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/06 20:18:43 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*int		is_map(char *s)
  {
  int	i;

  i = 0;
  while(s[i])
  {
  if(is_space(s[i]))
  i++;	
  else if (s[i] == '1' || s[i] == '0' || s[i] == 'N'|| s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
  return(1);
  }
  return (0);
  }*/

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
		if (tmp[0])
			break;
	}
	while(tmp != NULL)
	{
		tmp_join = ft_strjoin(tmp_join, tmp);
		tmp = get_next_line(data->fd);
	}
	data->map = ft_split(tmp_join, '\n');
}

void	parse_map(void)
{
	t_data	*data;

	data = _data();
	if (data->fd > 0)
	{
		store_map();
		int	i = 0;
		int	j;
		while(data->map[i])
		{
			j = 0;
			while(data->map[i][j])
			{
				printf("%c",data->map[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
		//store map and check it
		close(data->fd);
	}
}










































/*int	check_max(void)
  {	
  t_data	*data;
  char	*tmp;
  int		max;

  data = _data();
  max = 0;
  data->fd = open(data->path, O_RDONLY);
  if (data->fd > 0)
  {
  while(1)
  {
  tmp = get_next_line(data->fd);
  if (tmp[0] == '1' || tmp[0] == '0' || tmp[0] == 'N'
  || tmp[0] == 'S' || tmp[0] == 'E' || tmp[0] == 'W')
  break ;
  }
  while(tmp != NULL)
  {
  if (ft_strlen(tmp) > max)
  max = ft_strlen(tmp);
  tmp = get_next_line(data->fd);
  }
  close(data->fd);
  }
  return(max);
  }*/


