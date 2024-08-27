/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:07:18 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 16:07:56 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

#define SPECULAR_STRENGTH	0.5
#define SHININESS			64

static t_color	specular_light(t_inter poi, t_vector3 poi_light_dir,
	t_point_light *light, t_vector3 camera_poi)
{
	t_color		specular_color;
	t_vector3	reflect;
	double		angle;

	reflect = reflect_vector(scalar_prod(poi_light_dir, -1), poi.normal);
	angle = dot_product(reflect, camera_poi);
	ft_bzero(&specular_color, sizeof(t_color));
	if (angle <= 0)
		return (specular_color);
	specular_color.d_red = (SPECULAR_STRENGTH * pow(angle, SHININESS)
			* light->ratio * light->color.red) / 255;
	specular_color.d_green = (SPECULAR_STRENGTH * pow(angle, SHININESS)
			* light->ratio * light->color.green) / 255;
	specular_color.d_blue = (SPECULAR_STRENGTH * pow(angle, SHININESS)
			* light->ratio * light->color.blue) / 255;
	return (specular_color);
}

static t_color	diffuse_light(double angle, t_point_light *light)
{
	double	tmp_color;
	t_color	diffuse_color;

	tmp_color = (angle * light->ratio * light->color.red) / 255;
	diffuse_color.d_red = ft_dclamp(0, 1, tmp_color);
	tmp_color = (angle * light->ratio * light->color.green) / 255;
	diffuse_color.d_green = ft_dclamp(0, 1, tmp_color);
	tmp_color = (angle * light->ratio * light->color.blue) / 255;
	diffuse_color.d_blue = ft_dclamp(0, 1, tmp_color);
	return (diffuse_color);
}

t_color	compute_point_light(t_inter poi, t_ray poi_to_light, t_obj_list *lights,
	t_vector3 camera_pos)
{
	double			angle;
	t_color			diffuse_color;
	t_color			specular_color;
	t_point_light	*point_light;

	point_light = ft_objfind_id(lights, ID_LIGHT)->obj_struct;
	angle = dot_product(poi.normal, poi_to_light.dir);
	if (angle < 0)
		angle = 0;
	diffuse_color = diffuse_light(angle, point_light);
	specular_color = specular_light(poi, poi_to_light.dir, point_light,
			normalize_vector(vector_sub(poi.point, camera_pos)));
	diffuse_color.d_red = ft_dclamp(0, 1,
			diffuse_color.d_red + specular_color.d_red);
	diffuse_color.d_green = ft_dclamp(0, 1,
			diffuse_color.d_green + specular_color.d_green);
	diffuse_color.d_blue = ft_dclamp(0, 1,
			diffuse_color.d_blue + specular_color.d_blue);
	return (diffuse_color);
}
