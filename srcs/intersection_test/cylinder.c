/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:02:20 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/16 21:24:52 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdio.h>

#define NO_INTER -1

#define A 0
#define B 1
#define C 2

/*static double	get_body_dist(double abc[3], t_ray ray, t_cylinder *cylinder)
{
	double		t[2];
	double		test_height[2];
	double		disc;
	t_vector3	int_point;

	disc = (abc[B] * abc[B]) - (4 * abc[A] * abc[C]);
	if (disc < 0)
		return (-1);
	t[0] = (-abc[B] - sqrt(disc)) / (2 * abc[A]);
	t[1] = (-abc[B] + sqrt(disc)) / (2 * abc[A]);
	if (t[0] > t[1])
		swap_double(&t[0], &t[1]);
	int_point = vector_add(ray.origin, scalar_prod(ray.dir, t[0]));
	test_height[0] = dot_product(int_point, cylinder->axis);
	int_point = vector_add(ray.origin, scalar_prod(ray.dir, t[1]));
	test_height[1] = dot_product(int_point, cylinder->axis);
	if (test_height[0] > 0 && test_height[0] < cylinder->height)
		return (t[0]);
	if (test_height[1] > 0 && test_height[1] < cylinder->height)
		return (t[1]);
	else
		return (-1);
}

static t_vector3	get_body_normal(t_ray ray, t_cylinder *cylinder, double dist)
{
	double		tmp;
	t_vector3	tmp_poi;
	t_vector3	proj;
	t_vector3	normal;

	tmp_poi = compute_point(ray.origin, ray.dir, dist);
	proj = vector_sub(tmp_poi, cylinder->bot_center);
	tmp = dot_product(proj, cylinder->axis);
	proj = scalar_prod(cylinder->axis, tmp);
	tmp_poi = vector_sub(tmp_poi, cylinder->bot_center);
	proj = vector_sub(tmp_poi, proj);
	normal = normalize_vector(proj);
	return (normal);
}

static t_inter	compute_body(t_ray ray, t_cylinder *cylinder)
{
	double		t;
	double		abc[3];
	t_vector3	cam_to_cy;
	t_inter		result;

	cam_to_cy = vector_sub(ray.origin, cylinder->bot_center);
	abc[A] = dot_product(ray.dir, cylinder->axis);
	abc[A] *= abc[A];
	abc[A] = dot_product(ray.dir, ray.dir) - abc[A];
	abc[B] = dot_product(ray.dir, cylinder->axis);
	abc[B] *= dot_product(cam_to_cy, cylinder->axis);
	abc[B] = 2 * (dot_product(ray.dir, cam_to_cy) - abc[B]);
	abc[C] = dot_product(cam_to_cy, cam_to_cy);
	t = dot_product(cam_to_cy, cylinder->axis);
	t *= dot_product(cam_to_cy, cylinder->axis);
	abc[C] = abc[C] - t;
	abc[C] = abc[C] - (cylinder->radius * cylinder->radius);
	t = get_body_dist(abc, ray, cylinder);
//	if (t == -1)
//		return (-1);
	result.normal = get_body_normal(ray, cylinder, t);
	result.distance = t;
	return (result);
}*/

/*static double	test_intersection(t_ray ray, t_cylinder *cylinder, t_vector3 *normal)
{
	t_inter		caps;
	t_inter		body;

	body = compute_body(ray, cylinder);
	caps = compute_cap(ray, cylinder);
	if (caps.distance > 0 && (caps.distance < body.distance
		|| body.distance < 0))
	{
		*normal = caps.normal;
		return (caps.distance);
	}
	else if (body.distance > 0)
	{
		*normal = body.normal;
		return (body.distance);
	}
	else
		return (-1);
}*/

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
	abc[C] = dot_product(cam_to_cyl, cam_to_cyl) - dot_2 * dot_2 - 
		cyl->radius * cyl->radius;
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
