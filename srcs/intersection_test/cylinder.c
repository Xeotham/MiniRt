/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:02:20 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/29 23:53:58 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdio.h>

#define BODY 0
#define CAPS 1

#define TOP_CAP 0
#define BOT_CAP 1

#define A 0
#define B 1
#define C 2

static double	get_body_dist(double abc[3], t_ray ray, t_cylinder *cylinder)
{
	double		t[2];
	double		test_height[2];
	double		disc;
	t_vector3	tmp;

	disc = (abc[B] * abc[B]) - (4 * abc[A] * abc[C]);
	if (disc < 0)
		return (-1);
	t[0] = (-abc[B] - sqrt(disc)) / (2 * abc[A]);
	t[1] = (-abc[B] + sqrt(disc)) / (2 * abc[A]);
	if (t[0] > t[1])
		swap_double(&t[0], &t[1]);
	tmp = vector_add(ray.origin, scalar_prod(ray.dir, t[0]));
	test_height[0] = dot_product(tmp, cylinder->axis);
	tmp = vector_add(ray.origin, scalar_prod(ray.dir, t[1]));
	test_height[1] = dot_product(tmp, cylinder->axis);
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

	tmp_poi = scalar_prod(ray.dir, dist);
	tmp_poi = vector_add(ray.origin, tmp_poi);
	proj = vector_sub(tmp_poi, cylinder->coord);
	tmp = dot_product(proj, cylinder->axis);
	proj = scalar_prod(cylinder->axis, tmp);
	tmp_poi = vector_sub(tmp_poi, cylinder->coord);
	proj = vector_sub(tmp_poi, proj);
	normal = normalize_vector(proj);
	return (normal);
}

static double	compute_body(t_ray ray, t_cylinder *cylinder, t_vector3 *normal)
{
	double		t;
	double		abc[3];
	t_vector3	cam_to_cy;

	cam_to_cy = vector_sub(ray.origin, cylinder->coord);
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
	if (t == -1)
		return (-1);
	*normal = get_body_normal(ray, cylinder, t);
	return (t);
}

static double	test_cap(t_ray ray, t_cylinder *cylinder, double t[2],
				t_vector3 *normal)
{
	t_vector3	p[2];
	t_vector3	lifted_origin;

	lifted_origin = scalar_prod(cylinder->axis, cylinder->height);
	lifted_origin = vector_add(cylinder->coord, lifted_origin);
	p[BOT_CAP] = vector_add(ray.origin, scalar_prod(ray.dir, t[BOT_CAP]));
	p[TOP_CAP] = vector_add(ray.origin, scalar_prod(ray.dir, t[TOP_CAP]));
	p[BOT_CAP] = vector_sub(p[BOT_CAP], cylinder->coord);
	p[TOP_CAP] = vector_sub(p[TOP_CAP], lifted_origin);
	if (vector_norm(p[BOT_CAP]) <= cylinder->radius)
	{
		*normal = scalar_prod(cylinder->axis, -1);
		return (t[BOT_CAP]);
	}
	else if (vector_norm(p[TOP_CAP]) <= cylinder->radius)
	{
		*normal = cylinder->axis;
		return (t[TOP_CAP]);
	}
	else
		return (-1);
}

static double	compute_cap(t_ray ray, t_cylinder *cylinder, t_vector3 *normal)
{
	double		t[2];
	double		denom;
	t_vector3	cap[2];

	denom = dot_product(ray.dir, cylinder->axis);
	if (doubles_equals(denom, 0))
		return (-1);
	cap[TOP_CAP] = scalar_prod(cylinder->axis, cylinder->height);
	cap[TOP_CAP] = vector_add(cylinder->coord, cap[TOP_CAP]);
	cap[TOP_CAP] = vector_sub(cap[TOP_CAP], ray.origin);
	t[TOP_CAP] = (dot_product(cap[TOP_CAP], cylinder->axis)) / denom;
	cap[BOT_CAP] = vector_sub(cylinder->coord, ray.origin);
	t[BOT_CAP] = (dot_product(cap[BOT_CAP], cylinder->axis)) / denom;
	return (test_cap(ray, cylinder, t, normal));
}

static double	test_intersection(t_ray ray, t_cylinder *cylinder, t_vector3 *normal)
{
	double		solution[2];
	t_vector3	solution_normal[2];

	solution[BODY] = compute_body(ray, cylinder, &solution_normal[BODY]);
	solution[CAPS] = compute_cap(ray, cylinder, &solution_normal[CAPS]);
	if (solution[CAPS] > 0 && (solution[CAPS] < solution[BODY]
		|| solution[BODY] < 0))
	{
		*normal = solution_normal[CAPS];
		return (solution[CAPS]);
	}
	else if (solution[BODY] > 0)
	{
		*normal = solution_normal[BODY];
		return (solution[BODY]);
	}
	else
		return (-1);
}

t_inter	test_cylinder(t_ray ray, void *element)
{
	t_cylinder	*cylinder;
	t_inter		result;

	cylinder = (t_cylinder *)element;
	result.distance = test_intersection(ray, cylinder, &result.normal);
	result.point = compute_poi(ray, result.distance);
	result.color = cylinder->color;
	result.element = element;
	return (result);
}
