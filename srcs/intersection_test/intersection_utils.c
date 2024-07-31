/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:07:52 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/29 19:17:52 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vector3	compute_poi(t_ray ray, double distance)
{
	t_vector3	dir;
	t_vector3	poi;

	dir = scalar_prod(ray.dir, distance);
	poi = vector_add(ray.origin, dir);
	return (poi);
}

void	swap_double(double *to_swap_1, double *to_swap_2)
{
	double	tmp;

	tmp = *to_swap_1;
	(*to_swap_1) = (*to_swap_2);
	(*to_swap_2) = tmp;
}

double	test_cylinder_height(t_ray ray, t_cylinder *cylinder, double t)
{
	double	h_test;

	if (t < 0)
		return (-1);
	h_test = ray.origin.z + (t * ray.dir.z);
	if (h_test < cylinder->height)
		return (t);
	else
		return (-1);
}
