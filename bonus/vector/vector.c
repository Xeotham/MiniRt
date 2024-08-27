/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:02:14 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 13:34:17 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>
#include <mrt_vector.h>

t_vector3	set_vector(double x, double y, double z)
{
	t_vector3	n_vector;

	n_vector.x = x;
	n_vector.y = y;
	n_vector.z = z;
	return (n_vector);
}

t_vector3	create_vector(t_vector3 p1, t_vector3 p2)
{
	t_vector3	n_vector;

	n_vector.x = p2.x - p1.x;
	n_vector.y = p2.y - p1.y;
	n_vector.z = p2.z - p1.z;
	return (n_vector);
}

double	vector_norm(t_vector3 vector)
{
	return (sqrt((pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2))));
}

t_vector3	normalize_vector(t_vector3 vector)
{
	double		c_vector_norm;

	c_vector_norm = vector_norm(vector);
	if (!c_vector_norm)
		return (vector);
	return (scalar_div(vector, c_vector_norm));
}

double	dot_product(t_vector3 v1, t_vector3 v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}
