/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:55:07 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/03 19:15:05 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		size;

	size = ft_strlen(s1);
	result = ft_malloc(sizeof(char) * size + 1);
	result[size] = '\0';
	while (size--)
		result[size] = s1[size];
	return (result);
}
