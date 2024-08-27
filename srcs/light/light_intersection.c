/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:05:32 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 15:19:10 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	test_light(t_ray int_to_light, t_inter poi, t_obj_list *lights,
	t_obj_list *objects)
{
	int		color;
	double	angle;
	t_color	amb_light_color;
	t_color	point_light_color;

	color = 0xff;
	angle = dot_product(poi.normal, int_to_light.dir);
	if (angle < 0)
		angle = 0;
	if (!test_shadow(int_to_light, poi, objects))
		ft_bzero(&point_light_color, sizeof(t_color));
	else
		point_light_color = compute_point_light(angle, lights);
	amb_light_color = compute_amb_light(lights);
	color = poi.color.red
		* ft_dclamp(0, 1, point_light_color.d_red + amb_light_color.d_red);
	poi.color.red = ft_clamp(0, 255, color);
	color = poi.color.green
		* ft_dclamp(0, 1, point_light_color.d_green + amb_light_color.d_green);
	poi.color.green = ft_clamp(0, 255, color);
	color = poi.color.blue
		* ft_dclamp(0, 1, point_light_color.d_blue + amb_light_color.d_blue);
	poi.color.blue = ft_clamp(0, 255, color);
	color = set_rgba(poi.color.red, poi.color.green, poi.color.blue, 0xff);
	return (color);
}

int	light_test_inter(t_inter poi, t_obj_list *lights, t_obj_list *objects)
{
	int				color;
	t_ray			int_to_light;
	t_point_light	*point_light;

	point_light = ft_objfind_id(lights, ID_LIGHT)->obj_struct;
	int_to_light = create_ray(poi.point, point_light->coord);
	color = test_light(int_to_light, poi, lights, objects);
	return (color);
}
