/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:26:56 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/11 15:15:25 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mrt_vector.h>
#include <minirt.h>

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

t_vector3	scalar_multi(t_vector3 vector, double scalar)
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
