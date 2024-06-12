/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/12 14:08:50 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>


int	create_cylinder(char **info, t_minirt *minirt)
{
	t_obj_list	*obj;
	t_cylinder	*cylinder;

	if (ft_array_len(info) != 12)
		return (0);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	cylinder = ft_calloc(sizeof(t_cylinder), 1);
	if (!obj || !cylinder)
	{
		ft_multi_free(2, obj, cylinder);
		return (0);
	}
	obj->obj_id = MRT_CYLINDER;
	obj->obj_struct = cylinder;
	cylinder->coord = set_vector(ft_atod(info[1]), ft_atod(info[2]),
			ft_atod(info[3]));
	cylinder->axis = set_vector(ft_atod(info[4]), ft_atod(info[5]),
			ft_atod(info[6]));
	cylinder->diameter = ft_atod(info[7]);
	cylinder->height = ft_atod(info[8]);
	if (!ft_check_range(cylinder->axis.x, -1.0, 1.0)
		|| !ft_check_range(cylinder->axis.y, -1.0, 1.0)
		|| !ft_check_range(cylinder->axis.z, -1.0, 1.0)
		|| !set_color(&cylinder->color, ft_atoi(info[9]), ft_atoi(info[10]),
			ft_atoi(info[11])))
	{
		ft_multi_free(2, obj, cylinder);
		return (0);
	}
	ft_objadd_back(&minirt->object, obj);
	return (1);
}
