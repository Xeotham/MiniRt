/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:38:49 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 18:27:30 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static void	print_amb_help_menu(void)
{
	printf("==========\n");
	printf("Keys:\n");
	printf("Amb Light Mod:\n");
	printf("\t- ←: Decrease selected value.\n");
	printf("\t- →: Increase selected value.\n");
	printf("\t- Hold 1: Select Red modification.\n");
	printf("\t- Hold 2: Select Green modification.\n");
	printf("\t- Hold 3: Select Blue modification.\n");
	printf("\t- Hold B: Select Brightness modification.\n");
	printf("\nMods:\n");
	printf("\t- L: Unable/Disable Light Mod.\n");
	printf("\t- O: Unable/Disable Object Mod.\n");
	printf("\t- <: Switch to previous light.\n");
	printf("\t- >: Switch to next light.\n");
	printf("\t- Enter: Render the scene\n");
}

static void	print_point_help_menu(void)
{
	printf("==========\n");
	printf("Keys:\n");
	printf("Point Light Mod:\n");
	printf("\t- ←: Decrease selected value.\n");
	printf("\t- →: Increase selected value.\n");
	printf("\t- Hold Z: Select Z Axis modification.\n");
	printf("\t- Hold X: Select X Axis modification.\n");
	printf("\t- Hold C: Select Y Axis modification.\n");
	printf("\t- Hold B: Select Brightness modification.\n");
	printf("\nMods:\n");
	printf("\t- L: Unable/Disable Light Mod.\n");
	printf("\t- O: Unable/Disable Object Mod.\n");
	printf("\t- <: Switch to previous light.\n");
	printf("\t- >: Switch to next light.\n");
	printf("\t- Enter: Render the scene\n");
}

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
	print_amb_help_menu();
}

void	print_point_light(t_obj_list *light, t_obj_list *lst)
{
	t_point_light	*point_light;

	point_light = (t_point_light *)light->obj_struct;
	printf("==========\n");
	printf("Actually Modifying Point_light %zu\n",
		get_actual_obj_nb(light, lst));
	printf("==========\n");
	printf("Test %f\n", point_light->ratio);
	printf("Light Position:\n");
	printf("\tX: %.5lf, ", point_light->coord.x);
	printf("\tY: %.5lf, ", point_light->coord.y);
	printf("\tZ: %.5lf\n", point_light->coord.z);
	printf("Point Light Color:\n");
	print_gauge(255, point_light->color.red, "\033[31m", "Red");
	print_gauge(255, point_light->color.green, "\033[32m", "Green");
	print_gauge(255, point_light->color.blue, "\033[34m", "Blue");
	print_gauge(1, point_light->ratio, "\033[37m", "Brightness");
	print_point_help_menu();
}
