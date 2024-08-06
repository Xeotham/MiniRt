/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:21:09 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/05 14:00:01 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void modify_cylinder_coordinate(keys_t key, t_cylinder **cylinder,
    mlx_t *display)
{
    if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_Z))
		(*cylinder)->coord.z -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_Z))
		(*cylinder)->coord.z += 0.1;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_X))
		(*cylinder)->coord.x -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_X))
		(*cylinder)->coord.x += 0.1;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_C))
		(*cylinder)->coord.y -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_C))
		(*cylinder)->coord.y += 0.1;
}

static void modify_cylinder_axis(keys_t key, t_cylinder **cylinder,
    mlx_t *display)
{
    if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_Z))
		(*cylinder)->coord.z -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_Z))
		(*cylinder)->coord.z += 0.1;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_X))
		(*cylinder)->coord.x -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_X))
		(*cylinder)->coord.x += 0.1;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_C))
		(*cylinder)->coord.y -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_C))
		(*cylinder)->coord.y += 0.1;
	(*cylinder)->axis = normalize_vector((*cylinder)->axis);
}

static void modify_cylinder_size(keys_t key, t_cylinder **cylinder,
    mlx_t *display)
{
	if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_R)
		&& (*cylinder)->radius - 0.2 > 0)
		(*cylinder)->radius -= 0.2;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_R))
		(*cylinder)->radius += 0.2;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_H)
		&& (*cylinder)->height - 0.2 > 0)
		(*cylinder)->height -= 0.2;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_H))
		(*cylinder)->height += 0.2;
}

static void	modify_cylinder_color(keys_t key, t_cylinder **cylinder,
    mlx_t *display)
{
	if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_1)
		&& (*cylinder)->color.red - 1 >= 0)
		(*cylinder)->color.red--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_1)
		&& (*cylinder)->color.red + 1 <= 255)
		(*cylinder)->color.red++;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_2)
		&& (*cylinder)->color.green - 1 >= 0)
		(*cylinder)->color.green--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_2)
		&& (*cylinder)->color.green + 1 <= 255)
		(*cylinder)->color.green++;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_3)
		&& (*cylinder)->color.blue - 1 >= 0)
		(*cylinder)->color.blue--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_3)
		&& (*cylinder)->color.blue + 1 <= 255)
		(*cylinder)->color.blue++;
}

void	modify_cylinder(keys_t key, void **ptr, mlx_t *display)
{
	static bool	axis = false;
	t_cylinder		**cylinder;

	cylinder = (t_cylinder **)ptr;
	check_axis_state(key, &axis);
	if (!axis && ((key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
        && (mlx_is_key_down(display, MLX_KEY_Z)
        || mlx_is_key_down(display, MLX_KEY_X)
        || mlx_is_key_down(display, MLX_KEY_C))))
		modify_cylinder_coordinate(key, cylinder, display);
	else if (axis && ((key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
        && (mlx_is_key_down(display, MLX_KEY_Z)
        || mlx_is_key_down(display, MLX_KEY_X)
        || mlx_is_key_down(display, MLX_KEY_C))))
        modify_cylinder_axis(key, cylinder, display);
	else if ((key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
        && (mlx_is_key_down(display, MLX_KEY_R)
        || mlx_is_key_down(display, MLX_KEY_H)))
		modify_cylinder_size(key, cylinder, display);
	else if ((key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
        && (mlx_is_key_down(display, MLX_KEY_1)
        || mlx_is_key_down(display, MLX_KEY_2)
        || mlx_is_key_down(display, MLX_KEY_3)))
		modify_cylinder_color(key, cylinder, display);
}
