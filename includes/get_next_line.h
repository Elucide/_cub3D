/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:21:16 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/03 22:45:49 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16 
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buff_crumbs);
char	*ft_cut(char *buff_crumbs);
char	*ft_clean(char *buff_crumbs);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
int		gnl_strchr(char *s, int c);

#endif
