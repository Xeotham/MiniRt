/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:02:14 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/11 14:49:21 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mrt_vector.h>
#include <minirt.h>

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
	t_vector3	n_vector;
	double		c_vector_norm;
	
	c_vector_norm = vector_norm(vector);
	return (scalar_div(vector, c_vector_norm));
}

t_vector3	cross_product(t_vector3 v1, t_vector3 v2)
{
	t_vector3	n_vector;
	
	n_vector.x = (v1.y * v2.z) - (v2.y * v1.z);
	n_vector.y = (v1.z * v2.x) - (v2.z * v1.x);
	n_vector.z = (v1.x * v2.y) - (v2.x * v1.y);
	return (n_vector);
}

double	dot_product(t_vector3 v1, t_vector3 v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}
