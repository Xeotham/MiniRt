/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:26:42 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/08/26 15:24:41 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

#define NO_SOLUTION	-1

static double	compute_solution(double b, double discriminant)
{
	const double	sqrt_discriminant = sqrt(discriminant);
	const double	s1 = (-b + sqrt_discriminant) / 2;
	const double	s2 = (-b - sqrt_discriminant) / 2;

	if (s1 > 0 && (s1 < s2 || s2 < 0))
		return (s1);
	if (s2 > 0)
		return (s2);
	return (NO_SOLUTION);
}

static double	compute_equation(t_ray ray, t_vector3 center, double radius)
{
	const t_vector3	sp_coord = vector_sub(ray.origin, center);
	const double	b = 2 * dot_product(sp_coord, ray.dir);
	const double	c = dot_product(sp_coord, sp_coord) - radius * radius;
	const double	discriminant = b * b - 4 * c;
	double			solution;

	if (discriminant < 0)
		return (NO_SOLUTION);
	solution = compute_solution(b, discriminant);
	return (solution);
}

t_inter	test_sphere(t_ray ray, void *element)
{
	const t_sphere	*sphere = (t_sphere *) element;
	t_inter			result;

	result.distance = compute_equation(ray, sphere->coord, sphere->radius);
	if (result.distance == NO_SOLUTION)
		return (result);
	result.point = compute_point(ray.origin, ray.dir, result.distance);
	result.normal = create_vector(sphere->coord, result.point);
	result.normal = normalize_vector(result.normal);
	result.color = sphere->color;
	result.element = element;
	return (result);
}
