/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:25:34 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 13:34:13 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mrt_vector.h>

t_vector3	reflect_vector(t_vector3 to_reflect, t_vector3 axis)
{
	t_vector3	reflect;

	reflect = scalar_prod(axis, dot_product(axis, to_reflect));
	reflect = scalar_prod(reflect, 2);
	reflect = vector_sub(reflect, to_reflect);
	return (reflect);
}
