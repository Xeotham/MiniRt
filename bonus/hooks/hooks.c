/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:03:36 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/08/26 18:17:35 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

#define DRAW 	true
#define NO_DRAW	false
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

static bool	check_cam_key(keys_t key, action_t action, t_scene *scene)
{
	bool	draw;

	draw = NO_DRAW;
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
	else if ((key == MLX_KEY_PAGE_UP || key == MLX_KEY_PAGE_DOWN)
		&& (action == MLX_PRESS || (action == MLX_REPEAT
				&& scene->pixelation > 4)))
		draw = change_fov(key, scene->camera);
	else if ((key == MLX_KEY_Q || key == MLX_KEY_E) && action == MLX_PRESS)
		draw = rotate_key(key, scene->camera, scene->display);
	return (draw);
}

static bool	modify_elements(keys_t key, action_t action, t_scene *scene,
		bool *mods)
{
	bool	draw;

	draw = NO_DRAW;
	if (action == MLX_PRESS && (key == MLX_KEY_EQUAL
			|| key == MLX_KEY_MINUS))
		draw = change_pixelation(key, &scene->pixelation);
	else if (mods[LIGHT] == true && action != MLX_RELEASE
		&& (key == MLX_KEY_COMMA || key == MLX_KEY_PERIOD
			|| key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT || key == MLX_KEY_L))
		draw = modify_lights(key, scene->lights, scene);
	else if (mods[OBJ] == true && action != MLX_RELEASE
		&& (key == MLX_KEY_COMMA || key == MLX_KEY_PERIOD
			|| key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT
			|| key == MLX_KEY_M || key == MLX_KEY_O))
		draw = modify_objs(key, scene->objects, scene);
	return (draw);
}

void	key_pressed(mlx_key_data_t keydata, void *param)
{
	const keys_t	key = keydata.key;
	const action_t	action = keydata.action;
	bool			draw;
	t_scene			*scene;
	static bool		mods[2] = {false, false};

	scene = (t_scene *) param;
	draw = NO_DRAW;
	if (!type_to_move(key, action, &mods[LIGHT], &mods[OBJ]))
		return ;
	if (check_cam_key(key, action, scene)
		|| modify_elements(key, action, scene, mods))
		draw = DRAW;
	else if (key == MLX_KEY_INSERT && action == MLX_PRESS)
		take_screenshot(scene);
	print_menu(scene, NULL, mods);
	if (draw)
		draw_scene(scene, scene->pixelation);
}
