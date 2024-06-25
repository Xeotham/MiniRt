/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/25 14:16:47 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	create_plane(char **info, t_scene *scene)
{
	t_obj_list	*obj;
	t_plane		*plane;

	if (ft_array_len(info) != 4)
		return (0);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	plane = ft_calloc(sizeof(t_plane), 1);
	if (!obj || !plane)
	{
		ft_multi_free(2, obj, plane);
		return (0);
	}
	obj->obj_id = ID_PLANE;
	obj->obj_struct = plane;
	if (get_point(info[1], &plane->coord))
		return (0);
	if (get_vector(info[2], &plane->normal))
		return (0);
	if (get_color(info[3], &plane->color))
		return (0);
	ft_objadd_back(&scene->object, obj);
	return (1);
}
