/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:00:20 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/27 20:10:40 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert_digits(int n, char *result, int i, int numlen)
{
	int	j;
	int	temp;

	while (i < numlen)
	{
		j = i + 1;
		temp = n;
		while (j < numlen)
		{
			temp /= 10;
			j++;
		}
		result[i] = temp % 10 + '0';
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		index;
	int		numlen;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc(sizeof(char) * (ft_numlen(n) + 1));
	if (!result)
		return (NULL);
	index = 0;
	numlen = ft_numlen(n);
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
		index++;
	}
	return (convert_digits(n, result, index, numlen));
}
