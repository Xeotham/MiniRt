/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:47:07 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/06 09:24:07 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	print_gauge(int max, double value, char *color, char *value_name)
{
	double	load;
	double	i;

	i = 0;
	load = (20 * value) / max;
	if (value_name)
		printf("%s:\n", value_name);
	printf("╔════════════════════╗\n");
	printf("║%s", color);
	while (i < load)
	{
		printf("▓");
		i++;
	}
	while (i < 20)
	{
		printf(" ");
		i++;
	}
	printf("\033[0m║ %.0lf%% (%.2lf/%d)\n", ((100 * value) / max), value, max);
	printf("╚════════════════════╝\n");
}

static void	print_camera_info(t_camera *camera)
{
	printf("==========\n");
	printf("\033[1;3;4mActual Camera Info:\n");
	printf("\033[1;4mCamera position:\033[0m\n");
	printf("\tX: %.5lf, ", camera->orig.x);
	printf("\tY: %.5lf, ", camera->orig.y);
	printf("\tZ: %.5lf\n", camera->orig.z);
	printf("\033[1;4mCamera direction:\033[0m\n");
	printf("\tX: %.5lf, ", camera->direction.x);
	printf("\tY: %.5lf, ", camera->direction.y);
	printf("\tZ: %.5lf\n", camera->direction.z);
	printf("\033[1;4mCamera FOV:\033[0m %d\n", camera->fov);
}

void	print_menu(t_scene *scene, t_obj_list *obj)
{
	static t_camera		*camera = NULL;
	static t_obj_list	*actual_obj = NULL;

	if (!camera)
		camera = scene->camera;
	if (obj)
		actual_obj = obj;
	if (obj)
		return ;
	if (scene)
		printf("\033cActual Pixelation: %d\n", scene->pixelation);
	if (camera)
		print_camera_info(camera);
	if (actual_obj && actual_obj->obj_id == ID_AMB_LIGHT)
		print_amb_light(actual_obj->obj_struct);
	else if (actual_obj && actual_obj->obj_id == ID_LIGHT)
		print_point_light(actual_obj->obj_struct);
	else if (actual_obj && actual_obj->obj_id == ID_SPHERE)
		print_sphere_info(actual_obj, scene->objects);
	else if (actual_obj && actual_obj->obj_id == ID_PLANE)
		print_plane_info(actual_obj, scene->objects);
	else if (actual_obj && actual_obj->obj_id == ID_CYLINDER);
		print_cylinder_info(actual_obj, scene->objects);
}
