/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:07:52 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/20 23:52:10 by tde-la-r         ###   ########.fr       */
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
