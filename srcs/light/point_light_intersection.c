/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:07:18 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/31 20:22:50 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static double	compute_intensity(double angle, t_obj_list *lights)
{
	t_point_light	*light;
	t_amb_light		*amb_light;

	light = ft_objfind_id(lights, ID_LIGHT)->obj_struct;
	amb_light = ft_objfind_id(lights, ID_AMB_LIGHT)->obj_struct;
	if (angle > (PIE / 2))
		return (0);
	else
		return (light->ratio * (1.0 - (angle / (PIE / 2))));
}

t_color	compute_point_light(double angle, t_obj_list *lights, t_color color)
{
	double	intensity;
	t_color	light_color;
	int		red;
	int		green;
	int		blue;

	intensity = compute_intensity(angle, lights);
	red = color.red * intensity;
	light_color.red = ft_clamp(0, 255, red);
	green = color.green * intensity;
	light_color.green = ft_clamp(0, 255, green);
	blue = color.blue * intensity;
	light_color.blue = ft_clamp(0, 255, blue);
	return (light_color);
}
