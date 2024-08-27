/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:33:21 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/15 21:27:29 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

#define DRAW	true
#define NO_DRAW	false
#define LIGHT	0
#define OBJ		1

static void	modify_point_light_color(keys_t key, t_point_light **light,
	mlx_t *display)
{
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
}

static void	modify_point_light(keys_t key, void **ptr, mlx_t *display)
{
	t_point_light	**light;

	light = (t_point_light **)ptr;
	modify_point_light_color(key, light, display);
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
		&& (*light)->ratio - 0.01 >= 0)
		(*light)->ratio -= 0.01;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_B)
		&& (*light)->ratio + 0.01 <= 1)
		(*light)->ratio += 0.01;
}

static void	modify_ambiant_light_color(keys_t key, t_amb_light **light,
	mlx_t *display)
{
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
}

static void	modify_ambiant_light(keys_t key, void **ptr, mlx_t *display)
{
	t_amb_light	**light;

	light = (t_amb_light **)ptr;
	modify_ambiant_light_color(key, light, display);
	if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_B)
		&& (*light)->ratio - 0.01 >= 0)
		(*light)->ratio -= 0.01;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_B)
		&& (*light)->ratio + 0.01 <= 1)
		(*light)->ratio += 0.01;
}

bool	modify_lights(keys_t key, t_obj_list *lights, t_scene *scene)
{
	static t_obj_list	*actual_light = NULL;
	bool				ret;

	ret = DRAW;
	change_actual_obj(key, &actual_light, lights);
	if (actual_light->obj_id == ID_LIGHT)
		modify_point_light(key, &actual_light->obj_struct, scene->display);
	else if (actual_light->obj_id == ID_AMB_LIGHT)
		modify_ambiant_light(key, &actual_light->obj_struct, scene->display);
	print_menu(scene, actual_light, NULL);
	return (DRAW);
}
