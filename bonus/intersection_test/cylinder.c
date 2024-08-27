/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:02:20 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 15:18:35 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

#define NO_INTER -1

#define A 0
#define B 1
#define C 2

static bool	body_inter(double dist, t_ray ray, t_cylinder *cyl, t_inter *inter)
{
	t_vector3	inter_to_bot;	
	double		inter_height;
	t_vector3	cap_to_inter_height;
	t_vector3	radius_to_inter;

	inter->point = compute_point(ray.origin, ray.dir, dist);
	inter_to_bot = vector_sub(inter->point, cyl->bot_center);
	inter_height = dot_product(inter_to_bot, cyl->axis);
	if (inter_height > 0 && inter_height < cyl->height)
	{
		inter->distance = dist;
		cap_to_inter_height = scalar_prod(cyl->axis, inter_height);
		radius_to_inter = vector_sub(inter_to_bot, cap_to_inter_height);
		inter->normal = normalize_vector(radius_to_inter);
		return (true);
	}
	return (false);
}

static t_inter	compute_intersection(double abc[3], t_ray ray, t_cylinder *cyl)
{
	const double	discriminant = abc[B] * abc[B] - 4 * abc[A] * abc[C];
	double			s1;
	double			s2;
	bool			s1_in_body;
	t_inter			inter;

	if (discriminant < 0)
	{
		inter.distance = NO_INTER;
		return (inter);
	}
	s1 = (-abc[B] - sqrt(discriminant)) / (2 * abc[A]);
	s2 = (-abc[B] + sqrt(discriminant)) / (2 * abc[A]);
	if (s1 > s2)
		swap_double(&s1, &s2);
	s1_in_body = body_inter(s1, ray, cyl, &inter);
	if (s1 > 0 && s1_in_body)
		return (inter);
	if (s1 < 0 && s2 > 0 && s1_in_body)
		if (body_inter(s2, ray, cyl, &inter))
			return (inter);
	return (compute_cap(ray, cyl));
}

static t_inter	compute_cyl_equation(t_ray ray, t_cylinder *cyl)
{
	const t_vector3	cam_to_cyl = vector_sub(ray.origin, cyl->bot_center);
	const double	dot_1 = dot_product(ray.dir, cyl->axis);
	const double	dot_2 = dot_product(cam_to_cyl, cyl->axis);
	double			abc[3];

	abc[A] = 1 - dot_1 * dot_1;
	abc[B] = 2 * (dot_product(ray.dir, cam_to_cyl) - dot_1 * dot_2);
	abc[C] = dot_product(cam_to_cyl, cam_to_cyl) - dot_2 * dot_2
		- cyl->radius * cyl->radius;
	return (compute_intersection(abc, ray, cyl));
}

t_inter	test_cylinder(t_ray ray, void *element)
{
	t_cylinder	*cylinder;
	t_inter		result;

	cylinder = (t_cylinder *) element;
	if (vector_equals(ray.dir, cylinder->axis))
		result = compute_cap(ray, cylinder);
	else
		result = compute_cyl_equation(ray, cylinder);
	result.color = cylinder->color;
	result.element = element;
	return (result);
}
