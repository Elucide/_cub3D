/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:55:03 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/03 19:19:10 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_length(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		nb_len;
	long	l_n;

	l_n = n;
	nb_len = number_length(l_n);
	if (l_n < 0)
		nb_len += 1;
	result = ft_malloc(sizeof(char) * (nb_len + 1));
	if (l_n < 0)
	{
		result[0] = '-';
		l_n = -l_n;
	}
	if (l_n == 0)
		result[0] = 0 + '0';
	result[nb_len] = '\0';
	while (l_n != 0)
	{
		result[--nb_len] = l_n % 10 + '0';
		l_n = l_n / 10;
	}
	return (result);
}
