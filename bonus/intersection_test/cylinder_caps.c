/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:02:20 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 15:22:27 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

#define NO_INTER -1

static t_inter	cap_inter(t_vector3 cap_center, t_ray ray, t_cylinder *cyl)
{
	t_vector3	inter_to_cap_center;
	t_inter		result;

	result.distance = compute_plane_equation(cap_center, cyl->axis, ray);
	if (result.distance == NO_INTER)
		return (result);
	result.point = compute_point(ray.origin, ray.dir, result.distance);
	inter_to_cap_center = vector_sub(result.point, cap_center);
	if (vector_norm(inter_to_cap_center) > cyl->radius)
		result.distance = NO_INTER;
	return (result);
}

t_inter	compute_cap(t_ray ray, t_cylinder *cyl)
{
	t_inter		top_inter;
	t_inter		bot_inter;
	t_vector3	top_center;

	top_center = compute_point(cyl->bot_center, cyl->axis, cyl->height);
	top_inter = cap_inter(top_center, ray, cyl);
	top_inter.normal = cyl->axis;
	bot_inter = cap_inter(cyl->bot_center, ray, cyl);
	bot_inter.normal = scalar_prod(cyl->axis, -1);
	if (top_inter.distance != NO_INTER)
		if (bot_inter.distance == NO_INTER
			|| top_inter.distance < bot_inter.distance)
			return (top_inter);
	if (bot_inter.distance != NO_INTER)
		return (bot_inter);
	return (top_inter);
}
