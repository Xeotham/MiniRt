/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeo <xeo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:05:40 by xeo               #+#    #+#             */
/*   Updated: 2024/06/11 22:07:23 by xeo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <object.h>
#include <parser.h>

int	create_amb_light(char **info, t_minirt *minirt)
{
	t_obj_list	*obj;
	t_amb_light	*light;

	if (ft_objfind_id(minirt->light, MRT_AMB_LIGHT) || ft_array_len(info) > 5)
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
	if ((0.0 > light->ratio || light->ratio > 1.0) || !set_color(&light->color,
			ft_atoi(info[2]), ft_atoi(info[3]), ft_atoi(info[4])))
	{
		ft_multi_free(2, obj, light);
		return (0);
	}
	ft_objadd_back(&(*minirt->light), obj);
	return (1);
}

int	create_point_light(char **info, t_minirt *minirt)
{
	t_obj_list		*obj;
	t_point_light	*light;

	if (ft_objfind_id(minirt->light, MRT_LIGHT) || ft_array_len(info) > 5)
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
	if (0.0 > light->brightness || light->brightness > 1.0)
	{
		ft_multi_free(2, obj, light);
		return (0);
	}
	ft_objadd_back(&(*minirt->light), obj);
	return (1);
}
