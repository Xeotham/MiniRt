/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:03:36 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/31 20:22:39 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static const bool g_draw = true;
static const bool g_no_draw = false;
#define LIGHT	0
#define OBJ		1

void	end_display(void *param)
{
	mlx_t	*display;

	display = (mlx_t *) param;
	mlx_close_window(display);
}

static bool	translate_cam_press(keys_t key, t_camera *camera)
{
	t_vector3	right;
	t_vector3	above;

	if (key == MLX_KEY_W)
		camera->orig = vector_add(camera->orig, camera->direction);
	if (key == MLX_KEY_S)
		camera->orig = vector_sub(camera->orig, camera->direction);
	if (key == MLX_KEY_D || key == MLX_KEY_A)
	{
		right = normalize_vector(camera->u_screen);
		if (key == MLX_KEY_D)
			camera->orig = vector_add(camera->orig, right);
		if (key == MLX_KEY_A)
			camera->orig = vector_sub(camera->orig, right);
	}
	if (key == MLX_KEY_LEFT_SHIFT || key == MLX_KEY_SPACE)
	{
		above = normalize_vector(camera->v_screen);
		if (key == MLX_KEY_LEFT_SHIFT)
			camera->orig = vector_add(camera->orig, above);
		if (key == MLX_KEY_SPACE)
			camera->orig = vector_sub(camera->orig, above);
	}
	camera->screen_center = vector_add(camera->orig, camera->direction);
	return (g_draw);
}

static void	render_scene(t_scene *scene)
{
	static bool			render = false;

	if (render == false)
	{
		render = true;
		draw_scene(scene, 1);
	}
	else
	{
		render = false;
		draw_scene(scene, scene->pixelation);
	}
}

static bool	translate_cam_hold(keys_t key, t_camera *camera)
{
	t_vector3	right;
	t_vector3	above;

	if (key == MLX_KEY_W)
		camera->orig = vector_add(camera->orig, camera->direction);
	if (key == MLX_KEY_S)
		camera->orig = vector_sub(camera->orig, camera->direction);
	if (key == MLX_KEY_D || key == MLX_KEY_A)
	{
		right = normalize_vector(camera->u_screen);
		right = camera->u_screen;
//		right.x += 0.75; 
		if (key == MLX_KEY_D)
			camera->orig = vector_add(camera->orig, right);
		if (key == MLX_KEY_A)
			camera->orig = vector_sub(camera->orig, right);
	}
	if (key == MLX_KEY_LEFT_SHIFT || key == MLX_KEY_SPACE)
	{
		above = normalize_vector(camera->v_screen);
	//	above.z += 0.75;
		if (key == MLX_KEY_LEFT_SHIFT)
			camera->orig = vector_add(camera->orig, above);
		if (key == MLX_KEY_SPACE)
			camera->orig = vector_sub(camera->orig, above);
	}
	camera->screen_center = vector_add(camera->orig, camera->direction);
	//update_camera(camera);
	return (g_draw);
}

static bool	change_pixelation(keys_t key, int *pixelation)
{
	if (key == MLX_KEY_EQUAL && *pixelation + 1 < SCREEN_HEIGHT)
	{
		(*pixelation)++;
		return (g_draw);
	}
	else if (*pixelation - 1 > 0)
	{
		(*pixelation)--;
		return (g_draw);
	}
	return (g_no_draw);
}

static bool	change_fov(keys_t key, t_camera *camera)
{
	if (key == MLX_KEY_PAGE_UP && camera->fov + 5 < 180)
	{
		camera->fov += 5;
		update_camera(camera);
		return (g_draw);
	}
	else if (camera->fov - 5 > 0)
	{
		camera->fov -= 5;
		update_camera(camera);
		return (g_draw);
	}
	return (g_no_draw);
}

static void	print_actual_light(t_identifier id)
{
	if (id == ID_AMB_LIGHT)
		printf("Currently modifying the Ambiant Light.\n");
	else if (id == ID_LIGHT)
		printf("Currently modifying the Point Light.\n");
}

static void	modify_point_light(keys_t key, void **ptr, mlx_t *display)
{
	t_point_light	**light;

	light = (t_point_light **)ptr;
	if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_Z))
		(*light)->coord.z -= 0.5;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_Z))
		(*light)->coord.z += 0.5;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_X))
		(*light)->coord.x -= 0.5;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_X))
		(*light)->coord.x += 0.5;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_C))
		(*light)->coord.y -= 0.5;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_C))
		(*light)->coord.y += 0.5;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_B)
		&& (*light)->ratio - 0.1 >= 0)
		(*light)->ratio -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_B)
		&& (*light)->ratio + 0.1 <= 1)
		(*light)->ratio += 0.1;
}

static void	modify_ambiant_light(keys_t key, void **ptr, mlx_t *display)
{
	t_amb_light	**light;

	light = (t_amb_light **)ptr;
	if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_1)
		&& (*light)->color.red - 1 >= 0)
		(*light)->color.red--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_1)
		&& (*light)->color.red + 1 <= 255)
		(*light)->color.red++;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_2)
		&& (*light)->color.green - 1 >= 0)
		(*light)->color.green--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_2)
		&& (*light)->color.green + 1 <= 255)
		(*light)->color.green++;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_3)
		&& (*light)->color.blue - 1 >= 0)
		(*light)->color.blue--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_3)
		&& (*light)->color.blue + 1 <= 255)
		(*light)->color.blue++;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_B)
		&& (*light)->ratio - 0.1 >= 0)
		(*light)->ratio -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_B)
		&& (*light)->ratio + 0.1 <= 1)
		(*light)->ratio += 0.1;
	printf("Amb light color : Red %d, Green %d, Blue %d; Brightnes : %lf\n", (*light)->color.red, (*light)->color.green, (*light)->color.blue, (*light)->ratio);
}

static bool	modify_both_light(keys_t key, t_obj_list *lights, mlx_t *display)
{
	static t_obj_list	**actual_light = NULL;

	if (!actual_light || ((key == MLX_KEY_PERIOD || key == MLX_KEY_COMMA)
		&& !(*actual_light)->next))
	{
		actual_light = &lights;
		print_actual_light((*actual_light)->obj_id);
	}
	else if ((key == MLX_KEY_PERIOD || key == MLX_KEY_COMMA)
		&& (*actual_light)->next)
	{
		actual_light = &lights->next;
		print_actual_light((*actual_light)->obj_id);
	}
	else if ((*actual_light)->obj_id == ID_LIGHT)
		modify_point_light(key, &(*actual_light)->obj_struct, display);
	else if ((*actual_light)->obj_id == ID_AMB_LIGHT)
		modify_ambiant_light(key, &(*actual_light)->obj_struct, display);
	return (g_draw);
}
// static bool	change_objects(keys_t key, t_scene *scene, bool mods[2])
// {
// 	(void)key;
// 	(void)scene;
// 	(void)mods;
// 	return (true);
// }

static bool	type_to_move(keys_t key, action_t action, bool *light, bool *object)
{
	if (action != MLX_PRESS)
		return (true);
	if (key == MLX_KEY_L && ((*light) == false && (*object) == true))
	{
		ft_putstr_fd("Disable object mod first.\n", 2);
		return (false);
	}
	else if (key == MLX_KEY_O && (((*object) == false && (*light) == true)))
	{
		ft_putstr_fd("Disable light mod first.\n", 2);
		return (false);
	}
	else if (key == MLX_KEY_L)
		(*light) = !(*light);
	else if (key == MLX_KEY_O)
		(*object) = !(*object);
	if (key == MLX_KEY_L && (*light) == true)
		printf("Light mod unabled.\n");
	else if (key == MLX_KEY_L && (*light) == false)
		printf("Light mod disabled.\n");
	else if (key == MLX_KEY_O && (*object) == true)
		printf("Object mod unabled.\n");
	else if (key == MLX_KEY_O && (*object) == false)
		printf("Object mod disabled.\n");
	return (true);
}

void	key_pressed(mlx_key_data_t keydata, void *param)
{
	const keys_t	key = keydata.key;
	const action_t	action = keydata.action;
	bool			draw;
	t_scene			*scene;
	static bool		mods[2] = {false, false};

	scene = (t_scene *) param;
	draw = g_no_draw;
	if (!type_to_move(key, action, &mods[LIGHT], &mods[OBJ]))
		return ;
	if (key == MLX_KEY_ESCAPE && action == MLX_RELEASE)
		end_display(scene->display);
	else if (key == MLX_KEY_W || key == MLX_KEY_S
		|| key == MLX_KEY_A || key == MLX_KEY_D
		|| key == MLX_KEY_LEFT_SHIFT || key == MLX_KEY_SPACE)
	{
		if (action == MLX_PRESS)
			draw = translate_cam_press(key, scene->camera);
		else if (action == MLX_REPEAT && scene->pixelation > 4)
			draw = translate_cam_hold(key, scene->camera);
	}
	else if (key == MLX_KEY_ENTER && action == MLX_PRESS)
		render_scene(scene);
	else if (action == MLX_PRESS && (key == MLX_KEY_EQUAL || key == MLX_KEY_MINUS))
		draw = change_pixelation(key, &scene->pixelation);
	else if (key == MLX_KEY_PAGE_UP || key == MLX_KEY_PAGE_DOWN)
	{
		if (action == MLX_PRESS
			|| (action == MLX_REPEAT && scene->pixelation > 4))
			draw = change_fov(key, scene->camera);
	}
	else if (key == MLX_KEY_Q || key == MLX_KEY_E)
	{
		if (action == MLX_PRESS)
			draw = rotate_key(key, scene->camera, scene->display);
	}
	else if (mods[LIGHT] == true && action != MLX_RELEASE
		&& (key == MLX_KEY_COMMA || key == MLX_KEY_PERIOD
		|| key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT))
		draw = modify_both_light(key, scene->lights, scene->display);
	if (draw)
		draw_scene(scene, scene->pixelation);
}
