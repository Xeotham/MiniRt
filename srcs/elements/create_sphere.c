/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/27 13:46:54 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_error	create_sphere(char **info, t_scene *scene)
{
	t_obj_list	*obj;
	t_sphere	*sphere;

	if (ft_array_len(info) != 4)
		return (ERR_SP_INFO);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	sphere = ft_calloc(sizeof(t_sphere), 1);
	if (!obj || !sphere)
	{
		ft_multi_free(2, obj, sphere);
		return (ERR_MALLOC);
	}
	obj->obj_id = ID_SPHERE;
	obj->obj_struct = sphere;
	ft_objadd_back(&scene->object, obj);
	if (get_point(info[1], &sphere->coord))
		return (ERR_SP_COORD);
	if (get_measure(info[2], &sphere->diameter))
		return (ERR_SP_DIAM);
	if (get_color(info[3], &sphere->color))
		return (ERR_SP_COLOR);
	return (NO_ERR);
}
