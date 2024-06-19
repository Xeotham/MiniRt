/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/19 17:29:50 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	create_amb_light(char **info, t_scene *scene)
{
	t_obj_list	*obj;
	t_amb_light	*light;

	if (ft_objfind_id(scene->light, MRT_AMB_LIGHT) || ft_array_len(info) != 5)
		return (0);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	light = ft_calloc(sizeof(t_amb_light), 1);
	if (!obj || !light)
	{
		ft_multi_free(2, obj, light);
		return (0);
	}
	obj->obj_id = MRT_AMB_LIGHT;
	obj->obj_struct = light;
	light->ratio = ft_atod(info[1]);
	if (!ft_check_range(light->ratio, 0.0, 1.0) || !set_color(&light->color,
			ft_atoi(info[2]), ft_atoi(info[3]), ft_atoi(info[4])))
	{
		ft_multi_free(2, obj, light);
		return (0);
	}
	ft_objadd_back(&scene->light, obj);
	return (1);
}

int	create_point_light(char **info, t_scene *scene)
{
	t_obj_list		*obj;
	t_point_light	*light;

	if (ft_objfind_id(scene->light, MRT_LIGHT) || ft_array_len(info) != 5)
		return (0);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	light = ft_calloc(sizeof(t_amb_light), 1);
	if (!obj || !light)
	{
		ft_multi_free(2, obj, light);
		return (0);
	}
	obj->obj_id = MRT_LIGHT;
	obj->obj_struct = light;
	light->coord = set_vector(ft_atod(info[1]), ft_atod(info[2]),
			ft_atod(info[3]));
	light->brightness = ft_atod(info[4]);
	if (!ft_check_range(light->brightness, 0.0, 1.0))
	{
		ft_multi_free(2, obj, light);
		return (0);
	}
	ft_objadd_back(&scene->light, obj);
	return (1);
}
