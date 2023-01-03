/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:39:36 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/03 20:33:06 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./garbage.h"
# include "./get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


typedef struct s_data
{
	char	*path;
	int	fd;
}			t_data;

t_data	*_data(void);
void 	parse(void);

#endif
