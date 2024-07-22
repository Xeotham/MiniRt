/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:26:42 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/22 18:58:10 by tde-la-r         ###   ########.fr       */
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

static double	compute_equation(t_ray ray, double radius)
{
	double	b;
	double	c;
	double	discriminant;
	double	solution;

	b = 2 * dot_product(ray.origin, ray.dir);
	c = dot_product(ray.origin, ray.origin) - pow(radius, 2);
	discriminant = pow(b, 2) - 4 * c;
	if (discriminant < 0)
		return (no_solution);
	solution = compute_solution(b, discriminant);
	return (solution);
}

static t_ray	transform_ray(t_ray ray, t_vector3 sphere_center)
{
	ray.dir = normalize_vector(ray.dir);
	ray.origin = vector_sub(ray.origin, sphere_center);
	return (ray);
}

t_inter	test_sphere(t_ray ray, void *element)
{
	t_sphere	*sphere;
	t_inter		result;

	sphere = (t_sphere *) element;
	ray = transform_ray(ray, sphere->coord);
	result.distance = compute_equation(ray, sphere->radius);
	if (result.distance == no_solution)
		return (result);
	result.point = compute_poi(ray, result.distance);
	result.normal = create_vector(sphere->coord, result.point);
	result.normal = normalize_vector(poi_normal);
	result.color = sphere->color;
	result.element = element;
	return (result);
}
