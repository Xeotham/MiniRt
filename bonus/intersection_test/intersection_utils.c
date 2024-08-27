/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:07:52 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/08/26 13:32:21 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>
#include <mrt_vector.h>

t_vector3	compute_point(t_vector3 orig, t_vector3 dir, double distance)
{
	t_vector3	point;

	point = scalar_prod(dir, distance);
	point = vector_add(orig, point);
	return (point);
}

void	swap_double(double *to_swap_1, double *to_swap_2)
{
	double	tmp;

	tmp = *to_swap_1;
	(*to_swap_1) = (*to_swap_2);
	(*to_swap_2) = tmp;
}

bool	vector_equals(t_vector3 v1, t_vector3 v2)
{
	if (doubles_equals(v1.x, v2.x))
		if (doubles_equals(v1.y, v2.y))
			if (doubles_equals(v1.z, v2.z))
				return (true);
	return (false);
}
