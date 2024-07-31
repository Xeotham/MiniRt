/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:46:14 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/29 23:59:18 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	compute_pixel(t_ray ray, t_obj_list *elements, t_obj_list *lights)
{
	int				pixel;
	t_inter			test_result;
	t_inter			nearest_obj;
	const double	no_point = -1;
	t_obj_list		*obj_tested;

	nearest_obj.distance = no_point;
	obj_tested = elements;
	while (obj_tested)
	{
		test_result = obj_tested->test_inter(ray, obj_tested->obj_struct);
		if (nearest_obj.distance == no_point || \
				(test_result.distance != no_point && \
				test_result.distance < nearest_obj.distance))
			nearest_obj = test_result;
		obj_tested = obj_tested->next;
	}
	pixel = 0xff;
	if (nearest_obj.distance != no_point)
		pixel = light_test_inter(nearest_obj, lights, elements);
	return (pixel);
}

static void	draw_screen(t_scene *scene, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < scene->pixelation && y + i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < scene->pixelation && x + j < SCREEN_WIDTH)
		{
			mlx_put_pixel(scene->image, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_scene(t_scene *scene, int pixelation)
{
	int			x;
	int			y;
	int			pixel_color;
	const int	pixel_middle = pixelation / 2 + 0.5;
	t_ray		ray;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ray = cast_ray(scene->camera, x + pixel_middle, y + pixel_middle);
			pixel_color = compute_pixel(ray, scene->objects, scene->lights);
			draw_screen(scene, x, y, pixel_color);
			x += pixelation;
		}
		y += pixelation;
	}
	// printf("Camera x: %lf, y: %lf, z: %lf\n",scene->camera->orig.x, scene->camera->orig.y, scene->camera->orig.z);
}
