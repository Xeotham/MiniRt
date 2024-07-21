/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/21 18:09:23 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_error	get_informations(char **info, t_cylinder *cylinder)
{
	if (get_point(info[1], &cylinder->coord))
		return (ERR_CYL_COORD);
	if (get_vector(info[2], &cylinder->axis))
		return (ERR_CYL_AXIS);
	if (get_measure(info[3], &cylinder->diameter))
		return (ERR_CYL_DIAM);
	if (get_measure(info[4], &cylinder->height))
		return (ERR_CYL_HGT);
	if (get_color(info[5], &cylinder->color))
		return (ERR_CYL_COLOR);
	return (NO_ERR);
}

t_error	create_cylinder(char **info, t_scene *scene)
{
	t_obj_list	*obj;
	t_cylinder	*cylinder;
	t_error		ret;

	if (ft_array_len(info) != 6)
		return (ERR_CYL_INFO);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	cylinder = ft_calloc(sizeof(t_cylinder), 1);
	if (!obj || !cylinder)
	{
		ft_multi_free(2, obj, cylinder);
		return (ERR_MALLOC);
	}
	obj->obj_id = ID_CYLINDER;
	obj->obj_struct = cylinder;
	ft_objadd_back(&scene->objects, obj);
	ret = get_informations(info, cylinder);
	return (ret);
}
