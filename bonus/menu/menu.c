/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:47:07 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 18:29:04 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static void	print_mini_help_menu(void)
{
	printf("==========\nHelp Menu\n==========\n");
	printf("Keys:\n");
	printf("Camera:\n");
	printf("\t- W: Move the camera forward.\n");
	printf("\t- S: Move the camera backward.\n");
	printf("\t- A: Move the camera to the left.\n");
	printf("\t- D: Move the camera to the right.\n");
	printf("\t- Space: Move the camera up.\n");
	printf("\t- Shift: Move the camera down.\n");
	printf("\t- Q/scroll up: Change camera selected axis clockwise.\n");
	printf("\t- E/scroll down: Change camera selected axis anticlockwise.\n");
	printf("\t- Hold Z: Select Z axis.\n");
	printf("\t- Hold X: Select X axis.\n");
	printf("\t- Hold C: Select Y axis.\n");
	printf("\nMods:\n");
	printf("\t- L: Unable/Disable Light Mod.\n");
	printf("\t- O: Unable/Disable Object Mod.\n");
	printf("\t- Enter: Render the scene\n");
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

static void	print_info(t_obj_list *actual_obj, bool *mods_type, t_scene *scene)
{
	if (mods_type && mods_type[0] && actual_obj
		&& actual_obj->obj_id == ID_AMB_LIGHT)
		print_amb_light(actual_obj->obj_struct);
	else if (mods_type && mods_type[0] && actual_obj
		&& actual_obj->obj_id == ID_LIGHT)
		print_point_light(actual_obj, scene->lights);
	else if (mods_type && mods_type[1] && actual_obj
		&& actual_obj->obj_id == ID_SPHERE)
		print_sphere_info(actual_obj, scene->objects);
	else if (mods_type && mods_type[1] && actual_obj
		&& actual_obj->obj_id == ID_PLANE)
		print_plane_info(actual_obj, scene->objects);
	else if (mods_type && mods_type[1] && actual_obj
		&& actual_obj->obj_id == ID_CYLINDER)
		print_cylinder_info(actual_obj, scene->objects);
	else
		print_mini_help_menu();
}

void	print_menu(t_scene *scene, t_obj_list *obj, bool *mods)
{
	static t_camera		*camera = NULL;
	static t_obj_list	*actual_obj = NULL;
	static bool			*mods_type = NULL;

	if (!camera)
		camera = scene->camera;
	if (obj)
		actual_obj = obj;
	if (mods)
		mods_type = mods;
	else if (mods && !mods[0] && !mods[1])
		actual_obj = NULL;
	if (scene)
		printf("\033cActual Pixelation: %d\n", scene->pixelation);
	if (mods_type && mods_type[0])
		printf("Actual Mod: Light Mod\n");
	else if (mods_type && mods_type[1])
		printf("Actual Mod: Object Mod\n");
	else if (mods_type)
		printf("Actual Mod: Idle\n");
	if (camera)
		print_camera_info(camera);
	print_info(actual_obj, mods_type, scene);
}
