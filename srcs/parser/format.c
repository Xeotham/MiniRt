/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:51:57 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/06/25 14:07:01 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

const bool	error = true;

static char	*below_1_format(const char *nbr)
{
	while (*nbr == '0')
		nbr++;
	if (!*nbr || (*nbr != '.' && *nbr != '1'))
		return (nbr);
	if (*nbr == '1')
	{
		nbr++;
		if (*nbr != '.')
			return (nbr);
		nbr++;
		while (*nbr == '0')
			nbr++;
		return (nbr);
	}
	nbr++;
	while (ft_isdigit(*nbr))
		nbr++;
	return (nbr);
}

bool	get_light_ratio(const char *ratio, int *result)
{
	*result = ft_atoi(ratio);
	ratio = below_1_format(ratio);
	if (*ratio)
		return (error);
	return (false);
}

static char	*color_format(const char *color)
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

bool	get_color(const char *color, t_color *result)
{
	result->red = ft_atoi(color);
	color = color_format(color)
	if (!color || !*color)
		return (error);
	color++;
	result->green = ft_atoi(color);
	color = color_format(color)
	if (!color || !*color)
		return (error);
	color++;
	result->blue = ft_atoi(color);
	color = color_format(color)
	if (!color || *color)
		return (error);
	return (false);
}

static char	*measure_format(const char *measure)
{
	int	i;

	while (*measure == '0')
		measure++;
	i = 0;
	while (ft_isdigit(measure[i]) && i < 10)
		i++;
	if (measure[i] != '.')
		return (measure + i);
	i++;
	while (ft_isdigit(measure[i]))
		i++;
	return (measure + i);
}

bool	get_point(const char *point, t_vector3 *vector)
{
	vector->x = ft_atod(point);
	if (*point == '+' || *point == '-')
		point++;
	point = measure_format(point);
	if (*point != ',')
		return (error);
	point++;
	vector->y = ft_atod(point);
	if (*point == '+' || *point == '-')
		point++;
	point = measure_format(point);
	if (*point != ',')
		return (error);
	point++;
	vector->z = ft_atod(point);
	if (*point == '+' || *point == '-')
		point++;
	point = measure_format(point);
	if (*point)
		return (error);
	return (false);
}

bool	get_vector(const char *vector, t_vector3 *result)
{
	result->x = ft_atod(vector);
	if (*vector == '-' || *vector == '+')
		vector++;
	vector = below_1_number_format(vector);
	if (*vector != ',')
		return (error);
	vector++;
	result->y = ft_atod(vector);
	if (*vector == '-' || *vector == '+')
		vector++;
	vector = below_1_number_format(vector);
	if (*vector != ',')
		return (error);
	vector++;
	result->z = ft_atod(vector);
	if (*vector == '-' || *vector == '+')
		vector++;
	vector = below_1_number_format(vector);
	if (*vector != '\0')
		return (error);
	return (false);
}

bool	get_fov(const char *fov, int *result)
{
	int	i;

	*result = ft_atoi(fov);
	while (*fov == '0')
		fov++;
	i = 0;
	while (ft_isdigit(fov[i]) && i < 3)
		i++;
	if (fov[i])
		return (error);
	if (ft_strncmp(fov, "180", 3) > 0)
		return (error);
	return (false);
}

bool	get_measure(const char *measure, double *result)
{
	*result = ft_atod(measure);
	measure = measure_format(measure);
	if (*measure)
		return (error);
	return (false);
}
