/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:57:11 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 19:16:58 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

#define DRAW	true
#define NO_DRAW false
#define LIGHT	0
#define OBJ		1

bool	translate_cam_press(keys_t key, t_camera *camera)
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
	return (DRAW);
}

bool	translate_cam_hold(keys_t key, t_camera *camera)
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
	return (DRAW);
}

bool	change_pixelation(keys_t key, int *pixelation)
{
	if (key == MLX_KEY_EQUAL && *pixelation + 1 < SCREEN_HEIGHT)
	{
		(*pixelation)++;
		return (DRAW);
	}
	else if (*pixelation - 1 > 0)
	{
		(*pixelation)--;
		return (DRAW);
	}
	return (NO_DRAW);
}

bool	change_fov(keys_t key, t_camera *camera)
{
	if (key == MLX_KEY_PAGE_UP && camera->fov + 5 <= 180)
	{
		camera->fov += 5;
		update_camera(camera);
		return (DRAW);
	}
	else if (key == MLX_KEY_PAGE_DOWN && camera->fov - 5 > 0)
	{
		camera->fov -= 5;
		update_camera(camera);
		return (DRAW);
	}
	return (NO_DRAW);
}
