/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/19 17:29:50 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	create_sphere(char **info, t_scene *scene)
{
	t_obj_list	*obj;
	t_sphere	*sphere;

	if (ft_array_len(info) != 8)
		return (0);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	sphere = ft_calloc(sizeof(t_sphere), 1);
	if (!obj || !sphere)
	{
		ft_multi_free(2, obj, sphere);
		return (0);
	}
	obj->obj_id = MRT_SPHERE;
	obj->obj_struct = sphere;
	sphere->coord = set_vector(ft_atod(info[1]), ft_atod(info[2]),
			ft_atod(info[3]));
	sphere->diameter = ft_atod(info[4]);
	if (!set_color(&sphere->color, ft_atoi(info[5]), ft_atoi(info[6]),
			ft_atoi(info[7])))
	{
		ft_multi_free(2, obj, sphere);
		return (0);
	}
	ft_objadd_back(&scene->object, obj);
	return (1);
}
