/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:37:30 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 18:10:49 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static void	modify_plane_coordinates(keys_t key, t_plane **plane,
	mlx_t *display)
{
	if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_Z))
		(*plane)->coord.z -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_Z))
		(*plane)->coord.z += 0.1;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_X))
		(*plane)->coord.x -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_X))
		(*plane)->coord.x += 0.1;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_C))
		(*plane)->coord.y -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_C))
		(*plane)->coord.y += 0.1;
}

static void	modify_plane_normal(keys_t key, t_plane **plane,
	mlx_t *display)
{
	if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_Z))
		(*plane)->normal.z -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_Z))
		(*plane)->normal.z += 0.1;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_X))
		(*plane)->normal.x -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_X))
		(*plane)->normal.x += 0.1;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_C))
		(*plane)->normal.y -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_C))
		(*plane)->normal.y += 0.1;
	(*plane)->normal = normalize_vector((*plane)->normal);
}

static void	modify_plane_color(keys_t key, t_plane **plane,
	mlx_t *display)
{
	if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_1)
		&& (*plane)->color.red - 1 >= 0)
		(*plane)->color.red--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_1)
		&& (*plane)->color.red + 1 <= 255)
		(*plane)->color.red++;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_2)
		&& (*plane)->color.green - 1 >= 0)
		(*plane)->color.green--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_2)
		&& (*plane)->color.green + 1 <= 255)
		(*plane)->color.green++;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_3)
		&& (*plane)->color.blue - 1 >= 0)
		(*plane)->color.blue--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_3)
		&& (*plane)->color.blue + 1 <= 255)
		(*plane)->color.blue++;
}

void	modify_plane(keys_t key, void **ptr, mlx_t *display)
{
	t_plane		**plane;

	plane = (t_plane **)ptr;
	check_normal_state(key, &(*plane)->hooks_mod);
	if (!(*plane)->hooks_mod && ((key == MLX_KEY_LEFT
				|| key == MLX_KEY_RIGHT) && (mlx_is_key_down(display, MLX_KEY_Z)
				|| mlx_is_key_down(display, MLX_KEY_X)
				|| mlx_is_key_down(display, MLX_KEY_C))))
		modify_plane_coordinates(key, plane, display);
	else if ((*plane)->hooks_mod && ((key == MLX_KEY_LEFT
				|| key == MLX_KEY_RIGHT) && (mlx_is_key_down(display, MLX_KEY_Z)
				|| mlx_is_key_down(display, MLX_KEY_X)
				|| mlx_is_key_down(display, MLX_KEY_C))))
		modify_plane_normal(key, plane, display);
	else if (((key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
			&& (mlx_is_key_down(display, MLX_KEY_1)
				|| mlx_is_key_down(display, MLX_KEY_2)
				|| mlx_is_key_down(display, MLX_KEY_3))))
		modify_plane_color(key, plane, display);
}
