/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:51:57 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/21 18:28:01 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static const bool	g_error = true;

static char	*below_1_format(char *nbr)
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
		return (g_error);
	return (false);
}

static char	*color_format(char *color)
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

bool	get_color(char *color, t_color *result)
{
	result->red = ft_atoi(color);
	color = color_format(color);
	if (!color || !*color)
		return (g_error);
	color++;
	result->green = ft_atoi(color);
	color = color_format(color);
	if (!color || !*color)
		return (g_error);
	color++;
	result->blue = ft_atoi(color);
	color = color_format(color);
	if (!color || *color)
		return (g_error);
	return (false);
}

static char	*measure_format(char *measure)
{
	int	i;
	int	j;

	i = 0;
	while (measure[i] == '0')
		i++;
	j = 0;
	while (ft_isdigit(measure[i + j]) && j < 10)
		j++;
	if (!i + j || measure[i] != '.')
		return (measure + i + j);
	i++;
	while (ft_isdigit(measure[i + j]))
		i++;
	return (measure + i + j);
}

bool	get_point(char *point, t_vector3 *vector)
{
	vector->x = ft_atod(point);
	if (*point == '+' || *point == '-')
		point++;
	point = measure_format(point);
	if (*point != ',')
		return (g_error);
	point++;
	vector->y = ft_atod(point);
	if (*point == '+' || *point == '-')
		point++;
	point = measure_format(point);
	if (*point != ',')
		return (g_error);
	point++;
	vector->z = ft_atod(point);
	if (*point == '+' || *point == '-')
		point++;
	point = measure_format(point);
	if (*point)
		return (g_error);
	return (false);
}

bool	get_vector(char *vector, t_vector3 *result)
{
	result->x = ft_atod(vector);
	if (*vector == '-' || *vector == '+')
		vector++;
	vector = below_1_format(vector);
	if (*vector != ',')
		return (g_error);
	vector++;
	result->y = ft_atod(vector);
	if (*vector == '-' || *vector == '+')
		vector++;
	vector = below_1_format(vector);
	if (*vector != ',')
		return (g_error);
	vector++;
	result->z = ft_atod(vector);
	if (*vector == '-' || *vector == '+')
		vector++;
	vector = below_1_format(vector);
	if (*vector != '\0')
		return (g_error);
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
	if (fov[i])
		return (g_error);
	if (i == 3 && ft_strncmp(fov, "180", 3) > 0)
		return (g_error);
	return (false);
}

bool	get_measure(char *measure, double *result)
{
	*result = ft_atod(measure);
	measure = measure_format(measure);
	if (*measure)
		return (g_error);
	return (false);
}
