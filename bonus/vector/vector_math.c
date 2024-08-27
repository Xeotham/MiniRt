/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:26:56 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 13:34:15 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mrt_vector.h>
#include <minirt_bonus.h>

t_vector3	vector_add(t_vector3 v1, t_vector3 v2)
{
	t_vector3	n_vector;

	n_vector.x = v1.x + v2.x;
	n_vector.y = v1.y + v2.y;
	n_vector.z = v1.z + v2.z;
	return (n_vector);
}

t_vector3	vector_sub(t_vector3 v1, t_vector3 v2)
{
	t_vector3	n_vector;

	n_vector.x = v1.x - v2.x;
	n_vector.y = v1.y - v2.y;
	n_vector.z = v1.z - v2.z;
	return (n_vector);
}

t_vector3	scalar_prod(t_vector3 vector, double scalar)
{
	vector.x *= scalar;
	vector.y *= scalar;
	vector.z *= scalar;
	return (vector);
}

t_vector3	scalar_div(t_vector3 vector, double scalar)
{
	vector.x /= scalar;
	vector.y /= scalar;
	vector.z /= scalar;
	return (vector);
}

t_vector3	cross_product(t_vector3 v1, t_vector3 v2)
{
	t_vector3	n_vector;

	n_vector.x = (v1.y * v2.z) - (v2.y * v1.z);
	n_vector.y = (v1.z * v2.x) - (v2.z * v1.x);
	n_vector.z = (v1.x * v2.y) - (v2.x * v1.y);
	return (n_vector);
}
