/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:16:28 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/13 19:09:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

bool	test_shadow(t_ray int_to_light, t_inter poi, t_obj_list *objs)
{
	t_obj_list	*tmp;
	t_inter		intersection;
	double		light_distance;

	light_distance = vector_norm(create_vector(int_to_light.origin, \
		int_to_light.dest));
	tmp = objs;
	while (tmp)
	{
		if (poi.element == tmp->obj_struct)
		{
			tmp = tmp->next;
			continue ;
		}
		intersection = tmp->test_inter(int_to_light, tmp->obj_struct);
		if (intersection.distance != -1
			&& intersection.distance < light_distance)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
