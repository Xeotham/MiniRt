/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:51:57 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/06/24 15:00:08 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

const bool	error = true;

static char	*check_below_1_number(const char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i] == '0')
		i++;
	if (nbr[i] && nbr[i] != '.' && nbr[i] != '1')
		return (nbr + i);
	if (nbr[i] == '1')
	{
		i++;
		if (nbr[i] != '.' && nbr[i])
			return (nbr + i);
		if (nbr[i] && nbr[i + 1] != '0')
			return (nbr + i);
		return (nbr + i);
	}
	if (nbr[i])
		i++;
	while (ft_isdigit(nbr[i]))
		i++;
	if (nbr[i])
		return (nbr + i);
	return (nbr + i);
}

static char	*color_proper_format(const char *color)
{
	int	i;

	while (*color == '0')
		color++;
	i = 0;
	while (ft_isdigit(color[i]) && i < 3)
		i++;
	if (color[i] && color[i] != ',')
		return (NULL);
	if (ft_strncmp(color, "255", 3) > 0)
		return (NULL);
	return (color + i);
}

bool	check_color(const char *color)
{
	color = color_proper_format(color)
	if (!color || !*color)
		return (error);
	color++;
	color = color_proper_format(color)
	if (!color || !*color)
		return (error);
	color++;
	color = color_proper_format(color)
	if (!color || *color)
		return (error);
	return (false);
}

static char	*check_coordinates(const char *coord)
{
	int	i;

	if (*coord == '+' || *coord == '-')
		coord++;
	while (*coord == '0')
		coord++;
	i = 0;
	while (ft_isdigit(coord[i]) && i < 10)
		i++;
	if (coord[i] && coord[i] != ',' && coord[i] != '.')
		return (NULL);
	if (coord[i] == '.')
		i++;
	while (ft_isdigit(coord[i]))
		i++;
	if (coord[i] && coord[i] != ',')
		return (NULL);
	return (coord + i);
}

bool	check_point(const char *point)
{
	point = check_coordinates(point);
	if (!point || !*point)
		return (error);
	point++;
	point = check_coordinates(point)
	if (!point || !*point)
		return (error);
	point++;
	point = check_coordinates(point)
	if (!point || *point)
		return (error);
	return (false);
}

bool	check_vector(const char *vector)
{
	if (*vector == '-' || vector == '+')
		vector++;
	vector = check_below_1_number(vector);
	if (!vector)
}

bool	check_fov

bool	check_measurement
