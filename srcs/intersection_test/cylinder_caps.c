/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:02:20 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/30 13:04:13 by mhaouas          ###   ########.fr       */
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

double	compute_cap(t_ray ray, t_cylinder *cylinder, t_vector3 *normal)
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