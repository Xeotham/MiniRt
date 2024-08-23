/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant_light_intersection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:23:51 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/13 19:09:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

t_color	compute_amb_light(t_obj_list *lights)
{
	double		red;
	double		blue;
	double		green;
	t_color		amb_light_color;
	t_amb_light	*amb_light;

	amb_light = ft_objfind_id(lights, ID_AMB_LIGHT)->obj_struct;
	red = (amb_light->ratio * amb_light->color.red) / 255;
	amb_light_color.d_red = ft_dclamp(0, 1, red);
	green = (amb_light->ratio * amb_light->color.green) / 255;
	amb_light_color.d_green = ft_dclamp(0, 1, green);
	blue = (amb_light->ratio * amb_light->color.blue) / 255;
	amb_light_color.d_blue = ft_dclamp(0, 1, blue);
	return (amb_light_color);
}
