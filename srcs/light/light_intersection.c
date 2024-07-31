/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:05:32 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/30 14:54:14 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdio.h>

static int	test_light(t_ray int_to_light, t_inter poi, t_obj_list *lights,
	t_obj_list *objects)
{
	int		color;
	double	angle;
	t_color	amb_light_color;
	t_color	point_light_color;

	color = 0xff;
	angle = acos(dot_product(poi.normal, int_to_light.dir));
	if (!test_shadow(int_to_light, poi, objects))
		ft_bzero(&point_light_color, sizeof(t_color));
	else
		point_light_color = compute_point_light(angle, lights, poi.color);
	amb_light_color = compute_amb_light(lights, poi.color);
	color = point_light_color.red + amb_light_color.red;
	poi.color.red = ft_clamp(0, 255, color);
	color = point_light_color.green + amb_light_color.green;
	poi.color.green = ft_clamp(0, 255, color);
	color = point_light_color.blue + amb_light_color.blue;
	poi.color.blue = ft_clamp(0, 255, color);
	// poi.color.red = point_light_color.red + amb_light_color.red;
	// poi.color.green = point_light_color.green + amb_light_color.green;
	// poi.color.blue = point_light_color.blue + amb_light_color.blue;
	color = set_rgba(poi.color.red, poi.color.green, poi.color.blue, 0xff);
	return (color);
}

int light_test_inter(t_inter poi, t_obj_list *lights, t_obj_list *objects)
{
    t_ray   		int_to_light;
	t_point_light	*point_light;
	int				color;

	point_light = ft_objfind_id(lights, ID_LIGHT)->obj_struct;
    int_to_light = create_ray(poi.point, point_light->coord);
	color = test_light(int_to_light, poi, lights, objects);
	return (color);
}
