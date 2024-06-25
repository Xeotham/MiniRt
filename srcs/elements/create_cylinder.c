/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/25 14:04:55 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>


int	create_cylinder(char **info, t_scene *scene)
{
	t_obj_list	*obj;
	t_cylinder	*cylinder;

	if (ft_array_len(info) != 6)
		return (0);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	cylinder = ft_calloc(sizeof(t_cylinder), 1);
	if (!obj || !cylinder)
	{
		ft_multi_free(2, obj, cylinder);
		return (0);
	}
	obj->obj_id = ID_CYLINDER;
	obj->obj_struct = cylinder;
	if (get_point(info[1], &cylinder->coord))
		return (0);
	if (get_vector(info[2], &cylinder->axis))
		return (0);
	if (get_measure(info[3], &cylinder->diameter))
		return (0);
	if (get_measure(info[4], &cylinder->height))
		return (0);
	if (get_color(info[5], &cylinder->color))
		return (0);
	ft_objadd_back(&scene->object, obj);
	return (1);
}
