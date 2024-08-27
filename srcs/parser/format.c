/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:51:57 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/08/26 15:02:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERROR	true

char	*below_1_format(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i] == '0')
		i++;
	if (!nbr[i] || (!i && nbr[i] != '1') || (nbr[i] != '.' && nbr[i] != '1'))
		return (nbr + i);
	if (nbr[i] == '1')
	{
		i++;
		if (nbr[i] != '.')
			return (nbr + i);
		i++;
		while (nbr[i] == '0')
			i++;
		return (nbr + i);
	}
	i++;
	while (ft_isdigit(nbr[i]))
		i++;
	return (nbr + i);
}

bool	get_light_ratio(char *ratio, double *result)
{
	*result = ft_atod(ratio);
	ratio = below_1_format(ratio);
	if (*ratio)
		return (ERROR);
	return (false);
}

char	*color_format(char *color)
{
	int	i;

	while (*color == '0')
		color++;
	i = 0;
	while (ft_isdigit(color[i]) && i < 3)
		i++;
	if (color[i] && color[i] != ',')
		return (NULL);
	if (i == 3 && ft_strncmp(color, "255", 3) > 0)
		return (NULL);
	return (color + i);
}

char	*measure_format(char *measure)
{
	int	i;
	int	j;

	i = 0;
	while (measure[i] == '0')
		i++;
	j = 0;
	while (ft_isdigit(measure[i + j]) && j < 10)
		j++;
	if (!(i + j) || measure[i + j] != '.')
		return (measure + i + j);
	i++;
	while (ft_isdigit(measure[i + j]))
		i++;
	return (measure + i + j);
}
