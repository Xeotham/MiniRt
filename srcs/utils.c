/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:44:03 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/08/02 10:31:28 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	ft_clamp(int min, int max, int value)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	else
		return (value);
}

double	ft_dclamp(double min, double max, double value)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	else
		return (value);
}

void	create_double_color(t_color *color)
{
	color->d_red = color->red / 255;
	color->d_green = color->green / 255;
	color->d_blue = color->blue / 255;
}
