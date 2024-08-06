/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:03:36 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/08/06 08:52:23 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static const bool g_draw = true;
static const bool g_no_draw = false;
#define LIGHT	0
#define OBJ		1

void	end_display(void *param)
{
	mlx_t	*display;

	display = (mlx_t *) param;
	mlx_close_window(display);
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
		draw = modify_lights(key, scene->lights, scene);
	else if (mods[OBJ] == true && action != MLX_RELEASE
		&& (key == MLX_KEY_COMMA || key == MLX_KEY_PERIOD
		|| key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT || key == MLX_KEY_M))
		draw = modify_objs(key, scene->objects, scene);
	print_menu(scene, NULL);
	if (draw)
		draw_scene(scene, scene->pixelation);
}
