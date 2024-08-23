/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:08:18 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/13 19:09:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static void	modify_sphere_coordinate(keys_t key, t_sphere **sphere,
	mlx_t *display)
{
	if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_Z))
		(*sphere)->coord.z -= 0.25;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_Z))
		(*sphere)->coord.z += 0.25;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_X))
		(*sphere)->coord.x -= 0.25;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_X))
		(*sphere)->coord.x += 0.25;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_C))
		(*sphere)->coord.y -= 0.25;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_C))
		(*sphere)->coord.y += 0.25;
}

static void	modify_sphere_color(keys_t key, t_sphere **sphere,
	mlx_t *display)
{
	if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_1)
		&& (*sphere)->color.red - 1 >= 0)
		(*sphere)->color.red--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_1)
		&& (*sphere)->color.red + 1 <= 255)
		(*sphere)->color.red++;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_2)
		&& (*sphere)->color.green - 1 >= 0)
		(*sphere)->color.green--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_2)
		&& (*sphere)->color.green + 1 <= 255)
		(*sphere)->color.green++;
	else if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_3)
		&& (*sphere)->color.blue - 1 >= 0)
		(*sphere)->color.blue--;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_3)
		&& (*sphere)->color.blue + 1 <= 255)
		(*sphere)->color.blue++;
}

static void	modify_sphere_radius(keys_t key, t_sphere **sphere,
	mlx_t *display)
{
	if (key == MLX_KEY_LEFT && mlx_is_key_down(display, MLX_KEY_R)
		&& (*sphere)->radius - 0.1 > 0)
		(*sphere)->radius -= 0.1;
	else if (key == MLX_KEY_RIGHT && mlx_is_key_down(display, MLX_KEY_R))
		(*sphere)->radius += 0.1;
}

void	modify_sphere(keys_t key, void **ptr, mlx_t *display)
{
	t_sphere	**sphere;

	sphere = (t_sphere **)ptr;
	if ((key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
		&& (mlx_is_key_down(display, MLX_KEY_Z)
			|| mlx_is_key_down(display, MLX_KEY_X)
			|| mlx_is_key_down(display, MLX_KEY_C)))
		modify_sphere_coordinate(key, sphere, display);
	else if ((key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
		&& mlx_is_key_down(display, MLX_KEY_R))
		modify_sphere_radius(key, sphere, display);
	else if ((key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
		&& (mlx_is_key_down(display, MLX_KEY_1)
			|| mlx_is_key_down(display, MLX_KEY_2)
			|| mlx_is_key_down(display, MLX_KEY_3)))
		modify_sphere_color(key, sphere, display);
}
