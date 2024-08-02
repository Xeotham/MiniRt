/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:33:21 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/01 09:37:25 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static const bool g_draw = true;
static const bool g_no_draw = false;
#define LIGHT	0
#define OBJ		1


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
}

bool	modify_lights(keys_t key, t_obj_list *lights, mlx_t *display)
{
	static t_obj_list	**actual_light = NULL;

	if (!actual_light || ((key == MLX_KEY_PERIOD || key == MLX_KEY_COMMA)
		&& !(*actual_light)->next))
	{
		actual_light = &lights;
		print_actual_light((*actual_light)->obj_id);
		return (g_no_draw);
	}
	else if ((key == MLX_KEY_PERIOD || key == MLX_KEY_COMMA)
		&& (*actual_light)->next)
	{
		actual_light = &lights->next;
		print_actual_light((*actual_light)->obj_id);
		return (g_no_draw);
	}
	else if ((*actual_light)->obj_id == ID_LIGHT)
		modify_point_light(key, &(*actual_light)->obj_struct, display);
	else if ((*actual_light)->obj_id == ID_AMB_LIGHT)
		modify_ambiant_light(key, &(*actual_light)->obj_struct, display);
	return (g_draw);
}
