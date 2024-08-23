/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:57:31 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/22 14:44:42 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static void	print_sphere_help_menu(void)
{
	printf("==========\n");
	printf("Keys:\n");
	printf("Sphere Mod:\n");
	printf("\t- ←: Decrease selected value.\n");
	printf("\t- →: Increase selected value.\n");
	printf("\t- Hold Z: Select Z Axis modification.\n");
	printf("\t- Hold X: Select X Axis modification.\n");
	printf("\t- Hold C: Select Y Axis modification.\n");
	printf("\t- Hold R: Select radius modification.\n");
	printf("\t- Hold 1: Select Red modification.\n");
	printf("\t- Hold 2: Select Green modification.\n");
	printf("\t- Hold 3: Select Blue modification.\n");
	printf("\nMods:\n");
	printf("\t- L: Unable/Disable Light Mod.\n");
	printf("\t- O: Unable/Disable Object Mod.\n");
	printf("\t- <: Switch to previous object.\n");
	printf("\t- >: Switch to next object.\n");
	printf("\t- Enter: Render the scene\n");
}

static void	print_plane_help_menu(void)
{
	printf("==========\n");
	printf("Keys:\n");
	printf("Plane Mod:\n");
	printf("\t- M: Switch to coord/normal modification.\n");
	printf("\t- ←: Decrease selected value.\n");
	printf("\t- →: Increase selected value.\n");
	printf("\t- Hold Z: Select Z Axis modification.\n");
	printf("\t- Hold X: Select X Axis modification.\n");
	printf("\t- Hold C: Select Y Axis modification.\n");
	printf("\t- Hold 1: Select Red modification.\n");
	printf("\t- Hold 2: Select Green modification.\n");
	printf("\t- Hold 3: Select Blue modification.\n");
	printf("\nMods:\n");
	printf("\t- L: Unable/Disable Light Mod.\n");
	printf("\t- O: Unable/Disable Object Mod.\n");
	printf("\t- <: Switch to previous object.\n");
	printf("\t- >: Switch to next object.\n");
	printf("\t- Enter: Render the scene\n");
}

static void	print_cylinder_help_menu(void)
{
	printf("==========\n");
	printf("Keys:\n");
	printf("Cylinder Mod:\n");
	printf("\t- M: Switch to coord/normal modification.\n");
	printf("\t- ←: Decrease selected value.\n");
	printf("\t- →: Increase selected value.\n");
	printf("\t- Hold Z: Select Z Axis modification.\n");
	printf("\t- Hold X: Select X Axis modification.\n");
	printf("\t- Hold C: Select Y Axis modification.\n");
	printf("\t- Hold R: Select radius modification.\n");
	printf("\t- Hold H: Select height modification.\n");
	printf("\t- Hold 1: Select Red modification.\n");
	printf("\t- Hold 2: Select Green modification.\n");
	printf("\t- Hold 3: Select Blue modification.\n");
	printf("\nMods:\n");
	printf("\t- L: Unable/Disable Light Mod.\n");
	printf("\t- O: Unable/Disable Object Mod.\n");
	printf("\t- <: Switch to previous object.\n");
	printf("\t- >: Switch to next object.\n");
	printf("\t- Enter: Render the scene\n");
}

void	print_sphere_info(t_obj_list *obj, t_obj_list *lst)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)obj->obj_struct;
	printf("==========\n");
	printf("Actually Modifying Sphere number %zu\n",
		get_actual_obj_nb(obj, lst));
	printf("==========\n");
	printf("Sphere Position:\n");
	printf("\tX: %.5lf, ", sphere->coord.x);
	printf("\tY: %.5lf, ", sphere->coord.y);
	printf("\tZ: %.5lf\n", sphere->coord.z);
	printf("Sphere Radius : %lf\n", sphere->radius);
	printf("Sphere Color:\n");
	print_gauge(255, sphere->color.red, "\033[31m", "Red");
	print_gauge(255, sphere->color.green, "\033[32m", "Green");
	print_gauge(255, sphere->color.blue, "\033[34m", "Blue");
	print_sphere_help_menu();
}

void	print_plane_info(t_obj_list *obj, t_obj_list *lst)
{
	t_plane	*plane;

	plane = (t_plane *)obj->obj_struct;
	printf("==========\n");
	printf("Actually Modifying Plane number %zu\n",
		get_actual_obj_nb(obj, lst));
	printf("==========\n");
	printf("Plane Position:\n");
	printf("\tX: %.5lf, ", plane->coord.x);
	printf("\tY: %.5lf, ", plane->coord.y);
	printf("\tZ: %.5lf\n", plane->coord.z);
	printf("Plane Axis:\n");
	printf("\tX: %.5lf, ", plane->normal.x);
	printf("\tY: %.5lf, ", plane->normal.y);
	printf("\tZ: %.5lf\n", plane->normal.z);
	printf("Plane Color:\n");
	print_gauge(255, plane->color.red, "\033[31m", "Red");
	print_gauge(255, plane->color.green, "\033[32m", "Green");
	print_gauge(255, plane->color.blue, "\033[34m", "Blue");
	print_plane_help_menu();
}

void	print_cylinder_info(t_obj_list *obj, t_obj_list *lst)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)obj->obj_struct;
	printf("==========\n");
	printf("Actually Modifying Cylinder number %zu\n",
		get_actual_obj_nb(obj, lst));
	printf("==========\n");
	printf("Cylinder Position:\n");
	printf("\tX: %.5lf, ", cylinder->bot_center.x);
	printf("\tY: %.5lf, ", cylinder->bot_center.y);
	printf("\tZ: %.5lf\n", cylinder->bot_center.z);
	printf("Cylinder Axis:\n");
	printf("\tX: %.5lf, ", cylinder->axis.x);
	printf("\tY: %.5lf, ", cylinder->axis.y);
	printf("\tZ: %.5lf\n", cylinder->axis.z);
	printf("Cylinder Radius: %lf\n", cylinder->radius);
	printf("Cylinder Height: %lf\n", cylinder->height);
	printf("Cylinder Color:\n");
	print_gauge(255, cylinder->color.red, "\033[31m", "Red");
	print_gauge(255, cylinder->color.green, "\033[32m", "Green");
	print_gauge(255, cylinder->color.blue, "\033[34m", "Blue");
	print_cylinder_help_menu();
}
