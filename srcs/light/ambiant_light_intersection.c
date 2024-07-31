/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant_light_intersection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:23:51 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/31 20:24:25 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	compute_amb_light(t_obj_list *lights, t_color color)
{
	int			red;
	int			blue;
	int			green;
	t_color		amb_light_color;
	t_amb_light	*amb_light;

	amb_light = ft_objfind_id(lights, ID_AMB_LIGHT)->obj_struct;
	red = color.red * amb_light->color.red;
	amb_light_color.red = ft_clamp(0, 255, red) * amb_light->ratio;
	green = color.green * amb_light->color.green;
	amb_light_color.green = ft_clamp(0, 255, green) * amb_light->ratio;
	blue = color.blue * amb_light->color.blue;
	amb_light_color.blue = ft_clamp(0, 255, blue) * amb_light->ratio;
	return (amb_light_color);
}
