/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:46:14 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/26 18:08:22 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	compute_pixel(t_ray ray, t_scene *scene)
{
	int				pixel;
	t_inter			test;
	t_inter			nearest;
	const double	no_point = -1;
	const int		black = 255;
	t_obj_list		*elements;

	elements = scene->objects;
	nearest.distance = no_point;
	while (elements)
	{
		if (elements->obj_id == ID_SPHERE)
			test = test_sphere(ray, elements->obj_struct);
		if (elements->obj_id == ID_PLANE)
			test = test_plane(ray, elements->obj_struct);
		if (nearest.distance == no_point || (test.distance != no_point && test.distance < nearest.distance))
			nearest = test;
		elements = elements->next;
	}
	pixel = black;
	if (nearest.distance != no_point)
		pixel = light_test_inter(nearest, scene);
		// pixel = set_rgba(nearest.color.red, nearest.color.green, nearest.color.blue, 0xff);
	//	pixel = test_light(amb_light, point_light, nearest).color;
	return (pixel);
}

static void	init_display(t_scene *scene)
{
	const bool	no_resize = false;
	const char	title[] = "miniRT";

	scene->display = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, title, no_resize);
	if (!scene->display)
		exit_scene(NULL, 0, ERR_MLX);
	scene->image = mlx_new_image(scene->display, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!scene->image)
		exit_scene(NULL, 0, ERR_MLX);
	mlx_image_to_window(scene->display, scene->image, 0, 0);
}

void	draw_scene(t_scene *scene)
{
	int		x;
	int		y;
	t_ray	ray;
	int		pixel_color;

	init_display(scene);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ray = cast_ray(scene->camera, x, y);
			pixel_color = compute_pixel(ray, scene);
			mlx_put_pixel(scene->image, x, y, pixel_color);
			x++;
		}
		y++;
	}
}
