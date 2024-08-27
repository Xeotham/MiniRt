/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 13:31:12 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

t_error	create_amb_light(char **info, t_scene *scene)
{
	t_obj_list	*obj;
	t_amb_light	*light;

	if (ft_objfind_id(scene->lights, ID_AMB_LIGHT))
		return (ERR_ALGT_NB);
	if (ft_array_len(info) != 3)
		return (ERR_ALGT_INFO);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	light = ft_calloc(sizeof(*light), 1);
	if (!obj || !light)
	{
		ft_multi_free(2, obj, light);
		return (ERR_MALLOC);
	}
	obj->obj_id = ID_AMB_LIGHT;
	obj->obj_struct = light;
	ft_objadd_back(&scene->lights, obj);
	if (get_light_ratio(info[1], &light->ratio))
		return (ERR_ALGT_RATIO);
	if (get_color(info[2], &light->color))
		return (ERR_ALGT_COLOR);
	return (NO_ERR);
}

t_error	create_point_light(char **info, t_scene *scene)
{
	t_obj_list		*obj;
	t_point_light	*light;

	if (ft_array_len(info) != 3 && ft_array_len(info) != 4)
		return (ERR_LGT_INFO);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	light = ft_calloc(sizeof(*light), 1);
	if (!obj || !light)
	{
		ft_multi_free(2, obj, light);
		return (ERR_MALLOC);
	}
	obj->obj_id = ID_LIGHT;
	obj->obj_struct = light;
	ft_objadd_back(&scene->lights, obj);
	if (get_point(info[1], &light->coord))
		return (ERR_LGT_COORD);
	if (get_light_ratio(info[2], &light->ratio))
		return (ERR_LGT_RATIO);
	if (ft_array_len(info) == 4 && get_color(info[3], &light->color))
		return (ERR_ALGT_COLOR);
	else if (ft_array_len(info) == 3)
		ft_memset(&light->color, 255, sizeof(t_color));
	return (NO_ERR);
}
