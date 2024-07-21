/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:26:42 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/21 22:49:44 by mhaouas          ###   ########.fr       */
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

static double	compute_equation(t_ray ray, double radius, t_sphere *sphere)
{
	double	b;
	double	origin_norm;
	double	c;
	double	discriminant;
	double	solution;
	
	ray.dir.x += (sphere->coord.x / 10);
	ray.dir.y += (sphere->coord.y / 10);
	ray.dir.z += (sphere->coord.z / 10); 
	ray.dir = normalize_vector(ray.dir);
	b = 2 * dot_product(ray.origin, ray.dir);
	origin_norm = vector_norm(ray.origin);
	c = pow(origin_norm, 2) - pow(radius, 2);
	discriminant = pow(b, 2) - 4 * c;
	if (discriminant < 0)
		return (no_solution);
	solution = compute_solution(b, discriminant);
	return (solution);
}

t_inter	test_sphere(t_ray ray, void *element)
{
	t_sphere		*sphere;
	t_inter			result;
	t_vector3		poi_normal;

	sphere = (t_sphere *) element;
	result.distance = compute_equation(ray, sphere->radius, sphere);
	if (result.distance == no_solution)
		return (result);
	result.point = compute_poi(ray, result.distance);
	poi_normal = create_vector(sphere->coord, result.point);
	result.normal = normalize_vector(poi_normal);
	result.color = sphere->color;
	result.element = element;
	return (result);
}
