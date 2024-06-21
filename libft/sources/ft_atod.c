/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:34:35 by xeo               #+#    #+#             */
/*   Updated: 2024/06/21 12:54:28 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*atod_format(char *str, int *sign)
{
	*sign = 1;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

double	ft_atod(char *str)
{
	int		sign;
	double	integer;
	double	post_point;

	integer = 0.0;
	if (!str)
		return (0.0);
	str = atod_format(str, &sign);
	while ((*str >= '0' && *str <= '9') && *str != '.')
	{
		integer = integer * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	post_point = 0.0;
	while (*str >= '0' && *str <= '9')
	{
		post_point = post_point * 10 + (*str - '0');
		str++;
	}
	while (post_point > 1)
		post_point /= 10;
	return (integer * sign + post_point * sign);
}
