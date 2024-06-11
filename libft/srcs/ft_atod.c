/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeo <xeo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:34:35 by xeo               #+#    #+#             */
/*   Updated: 2024/06/11 21:34:58 by xeo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static double	atod_format(char **str)
{
	char	*tmp;
	double	sign;

	tmp = *str;
	sign = 1.0;
	while (*tmp == ' ' || ('\t' <= *tmp && *tmp <= '\r'))
		tmp++;
	if (*tmp == '-' || *tmp == '+')
		if ((*tmp)++ == '-')
			sign == -1.0;
	*str = tmp;
	return (sign);
}

double	ft_atod(char *str)
{
	double	nbr;
	double	sign;
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
