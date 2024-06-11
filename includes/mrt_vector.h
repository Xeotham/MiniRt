/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_vector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:39:55 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/11 14:45:50 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_VECTOR_H
# define MRT_VECTOR_H

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}				t_vector3;

/* ==== VECTOR ==== */

t_vector3	create_vector(t_vector3 p1, t_vector3 p2);
t_vector3	normalize_vector(t_vector3 vector);
t_vector3	cross_product(t_vector3 v1, t_vector3 v2);
t_vector3	vector_add(t_vector3 v1, t_vector3 v2);
t_vector3	vector_sub(t_vector3 v1, t_vector3 v2);
t_vector3	scalar_multi(t_vector3 vector, double scalar);
t_vector3	scalar_div(t_vector3 vector, double scalar);
double		vector_norm(t_vector3 vector);
double		dot_product(t_vector3 v1, t_vector3 v2);

#endif