/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:07:18 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/13 15:21:23 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	compute_point_light(double angle, t_obj_list *lights)
{
	double			tmp_color;
	t_color			light_color;
	t_point_light	*point_light;

	point_light = ft_objfind_id(lights, ID_LIGHT)->obj_struct;
	tmp_color = angle * point_light->ratio;
	light_color.d_red = ft_dclamp(0, 1, tmp_color);
	tmp_color = angle * point_light->ratio;
	light_color.d_green = ft_dclamp(0, 1, tmp_color);
	tmp_color = angle * point_light->ratio;
	light_color.d_blue = ft_dclamp(0, 1, tmp_color);
	return (light_color);
}
