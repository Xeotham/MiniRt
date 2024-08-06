/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:38:49 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/06 08:40:20 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	print_amb_light(void *obj)
{
	t_amb_light		*amb_light;

	amb_light = (t_amb_light *)obj;
	printf("==========\n");
	printf("Actually Modifying Amb_light\n");
	printf("==========\n");
	print_gauge(255, amb_light->color.red, "\033[31m", "Red");
	print_gauge(255, amb_light->color.green, "\033[32m", "Green");
	print_gauge(255, amb_light->color.blue, "\033[34m", "Blue");
	print_gauge(1, amb_light->ratio, "\033[37m", "Brightness");
}

void	print_point_light(void *obj)
{
	t_point_light	*point_light;

	point_light = (t_point_light *)obj;
	printf("==========\n");
	printf("Actually Modifying Point_light\n");
	printf("==========\n");
	printf("Light Position:\n");
	printf("\tX: %.5lf, ", point_light->coord.x);
	printf("\tY: %.5lf, ", point_light->coord.y);
	printf("\tZ: %.5lf\n", point_light->coord.z);
	print_gauge(1, point_light->ratio, "\033[37m", "Brightness");
}
