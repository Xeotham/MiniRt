/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/27 13:44:47 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_error	create_plane(char **info, t_scene *scene)
{
	t_obj_list	*obj;
	t_plane		*plane;

	if (ft_array_len(info) != 4)
		return (ERR_PL_INFO);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	plane = ft_calloc(sizeof(t_plane), 1);
	if (!obj || !plane)
	{
		ft_multi_free(2, obj, plane);
		return (ERR_MALLOC);
	}
	obj->obj_id = ID_PLANE;
	obj->obj_struct = plane;
	ft_objadd_back(&scene->object, obj);
	if (get_point(info[1], &plane->coord))
		return (ERR_PL_COORD);
	if (get_vector(info[2], &plane->normal))
		return (ERR_PL_NORM);
	if (get_color(info[3], &plane->color))
		return (ERR_PL_COLOR);
	return (NO_ERR);
}
