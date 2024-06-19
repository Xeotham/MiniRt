/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/19 17:29:50 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	create_plane(char **info, t_scene *scene)
{
	t_obj_list	*obj;
	t_plane		*plane;

	if (ft_array_len(info) != 10)
		return (0);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	plane = ft_calloc(sizeof(t_plane), 1);
	if (!obj || !plane)
	{
		ft_multi_free(2, obj, plane);
		return (0);
	}
	obj->obj_id = MRT_PLANE;
	obj->obj_struct = plane;
	plane->coord = set_vector(ft_atod(info[1]), ft_atod(info[2]),
			ft_atod(info[3]));
	plane->normal = set_vector(ft_atod(info[4]), ft_atod(info[5]),
			ft_atod(info[6]));
	if (!ft_check_range(plane->normal.x, -1.0, 1.0)
		|| !ft_check_range(plane->normal.y, -1.0, 1.0)
		|| !ft_check_range(plane->normal.z, -1.0, 1.0)
		|| !set_color(&plane->color, ft_atoi(info[7]), ft_atoi(info[8]),
			ft_atoi(info[9])))
	{
		ft_multi_free(2, obj, plane);
		return (0);
	}
	ft_objadd_back(&scene->object, obj);
	return (1);
}
