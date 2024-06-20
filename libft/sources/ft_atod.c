/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:34:35 by xeo               #+#    #+#             */
/*   Updated: 2024/06/20 16:42:48 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	atod_format(char *str)
{
	double	sign;

	sign = 1;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (sign);
}

double	ft_atod(char *str)
{
	int		sign;
	double	nbr;
	size_t	i;

	nbr = 0.0;
	i = 0;
	if (!str)
		return (0.0);
	sign = atod_format(&str);
	while ((*str >= '0' && *str <= '9') && *str != '.')
		nbr = nbr * 10 + (*(str++) - '0');
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*(str++) - '0');
		i++;
	}
	while (i-- > 0)
		nbr /= 10;
	return (nbr * sign);
}
