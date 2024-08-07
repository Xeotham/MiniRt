/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:26:42 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/26 17:40:23 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static const double	no_solution = -1;

static double	compute_solution(double b, double discriminant)
{
	double	sqrt_discriminant;
	double	s1;
	double	s2;

	sqrt_discriminant = sqrt(discriminant);
	s1 = (-b + sqrt_discriminant) / 2;
	s2 = (-b - sqrt_discriminant) / 2;
	if (s1 > 0 && (s1 < s2 || s2 < 0))
		return (s1);
	if (s2 > 0)
		return (s2);
	return (no_solution);
}

static double	compute_equation(t_ray ray, t_vector3 center, double radius)
{
	double	b;
	double	c;
	double	discriminant;
	double	solution;

	ray.origin = vector_sub(ray.origin, center);
	b = 2 * dot_product(ray.origin, ray.dir);
	c = dot_product(ray.origin, ray.origin) - pow(radius, 2);
	discriminant = pow(b, 2) - 4 * c;
	if (discriminant < 0 || doubles_equals(discriminant, 0))
		return (no_solution);
	solution = compute_solution(b, discriminant);
	return (solution);
}

t_inter	test_sphere(t_ray ray, void *element)
{
	t_sphere	*sphere;
	t_inter		result;

	sphere = (t_sphere *) element;
	result.distance = compute_equation(ray, sphere->coord, sphere->radius);
	if (result.distance == no_solution)
		return (result);
	result.point = compute_poi(ray, result.distance);
	result.normal = create_vector(sphere->coord, result.point);
	result.normal = normalize_vector(result.normal);
	result.color = sphere->color;
	result.element = element;
	return (result);
}
