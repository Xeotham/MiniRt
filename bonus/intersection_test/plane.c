/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:06:34 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/08/26 15:15:29 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

#define NO_SOLUTION	-1

double	compute_plane_equation(t_vector3 point, t_vector3 normal, t_ray ray)
{
	const double	denom = dot_product(normal, ray.dir);
	t_vector3		plane_to_orig;
	double			solution;

	if (doubles_equals(denom, 0))
		return (NO_SOLUTION);
	plane_to_orig = vector_sub(point, ray.origin);
	solution = dot_product(plane_to_orig, normal) / denom;
	if (solution < 0 || doubles_equals(solution, 0))
		return (NO_SOLUTION);
	return (solution);
}

t_inter	test_plane(t_ray ray, void *element)
{
	const t_plane	*plane = (t_plane *) element;
	t_inter			result;

	result.distance = compute_plane_equation(plane->coord, plane->normal, ray);
	if (result.distance == NO_SOLUTION)
		return (result);
	result.point = compute_point(ray.origin, ray.dir, result.distance);
	result.normal = plane->normal;
	result.color = plane->color;
	result.element = element;
	return (result);
}
