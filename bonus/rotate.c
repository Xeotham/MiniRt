/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:54:04 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/08/26 15:14:59 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static void	compute_rotation(double angle, double *coord1, double *coord2)
{
	const double	tmp = *coord1;

	*coord1 = *coord1 * cos(angle) - *coord2 * sin(angle);
	*coord2 = tmp * sin(angle) + *coord2 * cos(angle);
}

static bool	rotate_cam(double angle, t_camera *camera, mlx_t *display)
{
	bool	draw;

	draw = false;
	if (mlx_is_key_down(display, MLX_KEY_Z))
	{
		compute_rotation(angle, &camera->direction.x, &camera->direction.y);
		draw = true;
	}
	if (mlx_is_key_down(display, MLX_KEY_X))
	{
		compute_rotation(angle, &camera->direction.y, &camera->direction.z);
		draw = true;
	}
	if (mlx_is_key_down(display, MLX_KEY_C))
	{
		compute_rotation(angle, &camera->direction.z, &camera->direction.x);
		draw = true;
	}
	update_camera(camera);
	return (draw);
}

bool	rotate_key(keys_t key, t_camera *camera, mlx_t *display)
{
	double	angle;
	bool	draw;

	angle = 0.1;
	if (key == MLX_KEY_Q)
		angle *= -1;
	draw = rotate_cam(angle, camera, display);
	return (draw);
}

void	mouse_scrolling(double xdelta, double ydelta, void *param)
{
	t_scene	*scene;
	double	angle;

	(void) xdelta;
	scene = (t_scene *) param;
	angle = 0.035;
	if (ydelta < 0)
		angle *= -1;
	if (rotate_cam(angle, scene->camera, scene->display))
		draw_scene(scene, scene->pixelation);
}
