/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:11:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/25 14:21:15 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	create_sphere(char **info, t_scene *scene)
{
	t_obj_list	*obj;
	t_sphere	*sphere;

	if (ft_array_len(info) != 4)
		return (0);
	obj = ft_calloc(sizeof(t_obj_list), 1);
	sphere = ft_calloc(sizeof(t_sphere), 1);
	if (!obj || !sphere)
	{
		ft_multi_free(2, obj, sphere);
		return (0);
	}
	obj->obj_id = ID_SPHERE;
	obj->obj_struct = sphere;
	if (get_point(info[1], &sphere->coord))
		return (0);
	if (get_measure(info[2], &sphere->diameter))
		return (0);
	if (get_color(info[3], &sphere->color))
		return (0);
	ft_objadd_back(&scene->object, obj);
	return (1);
}
