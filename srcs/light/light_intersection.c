/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:05:32 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/26 17:58:26 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdio.h>

static bool	test_intersec(t_ray int_to_light, t_inter poi, t_obj_list *objs)
{
	t_obj_list	*tmp;
	t_inter		intersection;

	tmp = objs;
	while (tmp)
	{
		if (poi.element == tmp->obj_struct)
		{
			tmp = tmp->next;
			continue ;
		}
		intersection = tmp->test_inter(int_to_light, tmp->obj_struct);
		if (intersection.distance != -1)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}


static void	compute_light(double intensity, t_scene *scene, t_color *color)
{
	double		red;
	double		green;
	double		blue;
	t_amb_light	*amb_light;

	amb_light = ft_objfind_id(scene->lights, ID_AMB_LIGHT)->obj_struct;
	red = color->red * (intensity);
	green = color->green * (intensity);
	blue = color->blue * (intensity);
	color->red = red;
	color->green = green;
	color->blue = blue;
}

static double	compute_intensity(double angle, t_scene *scene)
{
	t_point_light	*light;
	t_amb_light		*amb_light;

	light = ft_objfind_id(scene->lights, ID_LIGHT)->obj_struct;
	amb_light = ft_objfind_id(scene->lights, ID_AMB_LIGHT)->obj_struct;
	if (angle > (PIE / 2))
		return (0);
	else
		return (light->ratio * (1.0 - (angle / (PIE / 2))));
}

static int	test_shadow(t_ray int_to_light, t_inter poi, t_scene *scene)
{
	int				color;
	double			angle;
	double			intensity;

	if (!test_intersec(int_to_light, poi, scene->objects))
		return (set_rgba(0, 0, 0, 0xff));
	color = 255;
	angle = acos(dot_product(poi.normal, int_to_light.dir));
	intensity = compute_intensity(angle, scene);
	compute_light(intensity, scene, &poi.color);
	color = set_rgba(poi.color.red, poi.color.green, poi.color.blue, 0xff);
	return (color);
}

int light_test_inter(t_inter poi, t_scene *scene)
{
    t_ray   		int_to_light;
	t_point_light	*point_light;
    t_amb_light     *amb_light;
	int				color;

	point_light = ft_objfind_id(scene->lights, ID_LIGHT)->obj_struct;
	amb_light = ft_objfind_id(scene->lights, ID_AMB_LIGHT)->obj_struct;
    int_to_light = create_ray(poi.point, point_light->coord);
	color = test_shadow(int_to_light, poi, scene);
	return (color);
}
