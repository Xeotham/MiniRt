/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_vector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:39:55 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 13:34:57 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_VECTOR_H
# define MRT_VECTOR_H

# include <stdbool.h>

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}			t_vector3;

/* ==== VECTOR ==== */

t_vector3	set_vector(double x, double y, double z);
t_vector3	create_vector(t_vector3 p1, t_vector3 p2);
t_vector3	normalize_vector(t_vector3 vector);
t_vector3	cross_product(t_vector3 v1, t_vector3 v2);
t_vector3	vector_add(t_vector3 v1, t_vector3 v2);
t_vector3	vector_sub(t_vector3 v1, t_vector3 v2);
t_vector3	scalar_prod(t_vector3 vector, double scalar);
t_vector3	scalar_div(t_vector3 vector, double scalar);
t_vector3	reflect_vector(t_vector3 to_reflect, t_vector3 axis);
double		vector_norm(t_vector3 vector);
double		dot_product(t_vector3 v1, t_vector3 v2);
bool		vector_equals(t_vector3 v1, t_vector3 v2);

#endif
