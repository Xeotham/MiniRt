/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:05:32 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 15:39:44 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static t_color	compute_new_color(t_color base_color, t_color color)
{
	t_color	new_color;

	new_color.d_red = ft_dclamp(0, 1, base_color.d_red + color.d_red);
	new_color.d_green = ft_dclamp(0, 1, base_color.d_green + color.d_green);
	new_color.d_blue = ft_dclamp(0, 1, base_color.d_blue + color.d_blue);
	return (new_color);
}

static t_color	multi_light_color(t_inter poi, t_scene *scene,
	t_color base_color)
{
	t_ray			poi_to_light;
	t_color			color;
	t_obj_list		*amb_light;
	t_obj_list		*actual_light;

	amb_light = ft_objfind_id(scene->lights, ID_AMB_LIGHT);
	actual_light = ft_objfind_id(scene->lights, ID_LIGHT);
	ft_bzero(&poi_to_light, sizeof(t_ray));
	ft_bzero(&color, sizeof(t_color));
	while (actual_light)
	{
		poi_to_light = create_ray(poi.point,
				((t_point_light *)(actual_light->obj_struct))->coord);
		if (!test_shadow(poi_to_light, poi, scene->objects))
			ft_bzero(&color, sizeof(t_color));
		else
			color = compute_point_light(poi, poi_to_light, actual_light,
					scene->camera->orig);
		base_color = compute_new_color(base_color, color);
		if (actual_light->next != amb_light)
			actual_light = actual_light->next;
		else
			actual_light = actual_light->next->next;
	}
	return (base_color);
}

static int	test_light(t_inter poi, t_scene *scene)
{
	int		color;
	t_color	amb_light_color;
	t_color	point_light_color;

	color = 0xff;
	ft_bzero(&point_light_color, sizeof(t_color));
	point_light_color = multi_light_color(poi, scene, point_light_color);
	amb_light_color = compute_amb_light(scene->lights);
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

int	light_test_inter(t_inter poi, t_scene *scene)
{
	int				color;

	color = test_light(poi, scene);
	return (color);
}
