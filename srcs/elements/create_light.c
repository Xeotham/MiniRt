/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/25 16:11:00 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	create_amb_light(char **info, t_scene *scene)
{
	t_obj_list	*obj;
	t_amb_light	*light;

	if (ft_objfind_id(scene->light, ID_AMB_LIGHT))
		return (ERR_);
	if (ft_array_len(info) != 3)
	obj = ft_calloc(sizeof(t_obj_list), 1);
	light = ft_calloc(sizeof(t_amb_light), 1);
	if (!obj || !light)
	{
		ft_multi_free(2, obj, light);
		return (0);
	}
	obj->obj_id = ID_AMB_LIGHT;
	obj->obj_struct = light;
	if (get_light_ratio(info[1], &light->ratio))
		return (0);
	if (get_color(info[2], &light->color))
		return (0);
	ft_objadd_back(&scene->light, obj);
	return (1);
}

int	create_point_light(char **info, t_scene *scene)
{
	t_obj_list		*obj;
	t_point_light	*light;

	if (ft_objfind_id(scene->light, ID_LIGHT) || ft_array_len(info) != 4)
		return (0);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	light = ft_calloc(sizeof(t_amb_light), 1);
	if (!obj || !light)
	{
		ft_multi_free(2, obj, light);
		return (0);
	}
	obj->obj_id = ID_LIGHT;
	obj->obj_struct = light;
	if (get_point(info[1], &light->coord))
		return (0);
	if (get_light_ratio(info[2], &light->ratio))
		return (0);
	ft_objadd_back(&scene->light, obj);
	return (1);
}
