/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:51:57 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/06/24 15:52:36 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

const bool	error = true;

static char	*check_below_1_number(const char *nbr)
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

bool	check_light_ratio(const char *ratio)
{
	ratio = check_below_1_number(ratio);
	if (*ratio)
		return (error);
	return (false);
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
	int	i;

	i = 0;
	while (i < 2)
	{
		color = color_proper_format(color)
		if (!color || !*color)
			return (error);
		color++;
		i++;
	}
	color = color_proper_format(color)
	if (!color || *color)
		return (error);
	return (false);
}

static char	*check_measure(const char *coord)
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

bool	check_point(const char *point)
{
	int	i;
	
	i = 0;
	while (i < 2)
	{
		if (*point == '+' || *point == '-')
			point++;
		point = check_measure(point);
		if (*point != ',')
			return (error);
		point++;
		i++;
	}
	if (*point == '+' || *point == '-')
		point++;
	point = check_measure(point)
	if (*point)
		return (error);
	return (false);
}

bool	check_vector(const char *vector)
{
	int	i;
	
	i = 0;
	while (i < 2)
	{
		if (*vector == '-' || *vector == '+')
			vector++;
		vector = check_below_1_number(vector);
		if (*vector != ',')
			return (error);
		vector++;
		i++;
	}
	if (*vector == '-' || *vector == '+')
		vector++;
	vector = check_below_1_number(vector);
	if (*vector != '\0')
		return (error);
	return (false);
}

bool	check_fov(const char *fov)
{
	int	i;

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

bool	check_measure(const char *measure)
{
	measure = check_measure(measure);
	if (*measure)
		return (error);
	return (false);
}
