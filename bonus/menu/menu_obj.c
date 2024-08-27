/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:57:31 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 18:09:58 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

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
	printf("Plane mod: ");
	if (!plane->hooks_mod)
		printf("Coordinate modification\n");
	else
		printf("Normal modification\n");
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
	printf("Cylinder mod: ");
	if (!cylinder->hooks_mod)
		printf("Coordinate modification\n");
	else
		printf("axis modification\n");
	printf("Cylinder Position:\n\tX: %.5lf, \tY: %.5lf, \tZ: %.5lf\n",
		cylinder->center.x, cylinder->center.y, cylinder->center.z);
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
