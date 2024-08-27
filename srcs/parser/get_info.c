/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:44:48 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 15:00:57 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERROR	true

bool	get_color(char *color, t_color *result)
{
	result->red = ft_atoi(color);
	color = color_format(color);
	if (!color || !*color)
		return (ERROR);
	color++;
	result->green = ft_atoi(color);
	color = color_format(color);
	if (!color || !*color)
		return (ERROR);
	color++;
	result->blue = ft_atoi(color);
	color = color_format(color);
	if (!color || *color)
		return (ERROR);
	return (false);
}

bool	get_point(char *point, t_vector3 *vector)
{
	vector->x = ft_atod(point);
	if (*point == '+' || *point == '-')
		point++;
	point = measure_format(point);
	if (*point != ',')
		return (ERROR);
	point++;
	vector->y = ft_atod(point);
	if (*point == '+' || *point == '-')
		point++;
	point = measure_format(point);
	if (*point != ',')
		return (ERROR);
	point++;
	vector->z = ft_atod(point);
	if (*point == '+' || *point == '-')
		point++;
	point = measure_format(point);
	if (*point)
		return (ERROR);
	return (false);
}

bool	get_vector(char *vector, t_vector3 *result)
{
	result->x = ft_atod(vector);
	if (*vector == '-' || *vector == '+')
		vector++;
	vector = below_1_format(vector);
	if (*vector != ',')
		return (ERROR);
	vector++;
	result->y = ft_atod(vector);
	if (*vector == '-' || *vector == '+')
		vector++;
	vector = below_1_format(vector);
	if (*vector != ',')
		return (ERROR);
	vector++;
	result->z = ft_atod(vector);
	if (*vector == '-' || *vector == '+')
		vector++;
	vector = below_1_format(vector);
	if (*vector != '\0')
		return (ERROR);
	*result = normalize_vector(*result);
	return (false);
}

bool	get_fov(char *fov, int *result)
{
	int	i;

	*result = ft_atoi(fov);
	while (*fov == '0')
		fov++;
	i = 0;
	while (ft_isdigit(fov[i]) && i < 3)
		i++;
	if (!i || fov[i])
		return (ERROR);
	if (i == 3 && ft_strncmp(fov, "180", 3) > 0)
		return (ERROR);
	return (false);
}

bool	get_measure(char *measure, double *result)
{
	*result = ft_atod(measure);
	measure = measure_format(measure);
	if (*measure)
		return (ERROR);
	return (false);
}
