/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:49:04 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/13 19:09:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static void	normalize_coordinate(double *coord_x, double *coord_y)
{
	(*coord_x) = ((*coord_x) * (1.0 / (SCREEN_WIDTH / 2.0))) - 1.0;
	(*coord_y) = ((*coord_y) * (1.0 / (SCREEN_HEIGHT / 2.0))) - 1.0;
}

t_ray	create_ray(t_vector3 point_1, t_vector3 point_2)
{
	t_ray	ray;

	ray.origin = point_1;
	ray.dest = point_2;
	ray.dir = create_vector(point_1, point_2);
	ray.dir = normalize_vector(ray.dir);
	return (ray);
}

t_ray	cast_ray(t_camera *camera, double coord_x, double coord_y)
{
	t_ray		ray;
	t_vector3	translated_x;
	t_vector3	translated_y;
	t_vector3	translated_coordinate;

	normalize_coordinate(&coord_x, &coord_y);
	translated_x = scalar_prod(camera->u_screen, coord_x);
	translated_y = scalar_prod(camera->v_screen, coord_y);
	translated_coordinate = vector_add(camera->screen_center, translated_x);
	translated_coordinate = vector_add(translated_coordinate, translated_y);
	ray = create_ray(camera->orig, translated_coordinate);
	return (ray);
}
