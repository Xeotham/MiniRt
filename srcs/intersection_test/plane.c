/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:06:34 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/08/16 21:20:22 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//static const bool	g_error = true;
//static const bool	g_no_error = false;
static const double	g_no_solution = -1;

/*static t_matrix	set_transform_matrix(t_vector3 axis, double angle)
{
	t_matrix	new;
	double		c;
	double		s;
	double		minus_c;

	new = create_matrix(4, 4);
	if (!new)
		return (NULL);
	identity_matrix(new);
	c = cos(angle);
	s = sin(angle);
	minus_c = 1 - c;
	new[0][0] = axis.x * axis.x * minus_c + c;
	new[0][1] = axis.x * axis.y * minus_c - axis.z * s;
	new[0][2] = axis.x * axis.z * minus_c + axis.y * s;
	new[1][0] = axis.y * axis.x * minus_c + axis.z * s;
	new[1][1] = axis.y * axis.y * minus_c + c;
	new[1][2] = axis.y * axis.z * minus_c - axis.x * s;
	new[2][0] = axis.z * axis.x * minus_c - axis.y * s;
	new[2][1] = axis.z * axis.y * minus_c + axis.x * s;
	new[2][2] = axis.z * axis.z * minus_c + c;
	return (new);
}

static bool	transform_ray(t_ray *ray, t_plane *plane)
{
	t_vector3	up;
	double		rot_angle;
	t_vector3	rot_axis;
	t_matrix	matrix;

	up = set_vector(0, 0, 1);
	rot_angle = dot_product(plane->normal, up);
	rot_angle = acos(rot_angle);
	rot_axis = cross_product(plane->normal, up);
	rot_axis = normalize_vector(rot_axis);
	matrix = set_transform_matrix(rot_axis, rot_angle);
	if (!matrix)
		return (g_error);
	if (mat_vec_product(matrix, &ray->origin) || \
			mat_vec_product(matrix, &ray->dir))
	{
		ft_free_2d_array(matrix, 4);
		return (g_error);
	}
	ft_free_2d_array(matrix, 4);
	ray->origin.z -= plane->coord.z;
	ray->dir = normalize_vector(ray->dir);
	return (g_no_error);
}

static double	compute_equation(double z_orig, double z_dir)
{
	if (doubles_equals(z_dir, 0))
		return (g_no_solution);
	return (-z_orig / z_dir);
}*/

double	compute_plane_equation(t_vector3 point, t_vector3 normal, t_ray ray)
{
	const double	denom = dot_product(normal, ray.dir);
	t_vector3		plane_to_orig;
	double			solution;

	if (doubles_equals(denom, 0))
		return (g_no_solution);
	plane_to_orig = vector_sub(point, ray.origin);
	solution = dot_product(plane_to_orig, normal) / denom;
	if (solution < 0 || doubles_equals(solution, 0))
		return (g_no_solution);
	return (solution);
}

t_inter	test_plane(t_ray ray, void *element)
{
	const t_plane	*plane = (t_plane *) element;
	t_inter			result;

	result.distance = compute_plane_equation(plane->coord, plane->normal, ray);
	if (result.distance == g_no_solution)
		return (result);
	result.point = compute_point(ray.origin, ray.dir, result.distance);
	result.normal = plane->normal;
	result.color = plane->color;
	result.element = element;
	return (result);
}
