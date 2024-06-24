/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:57:35 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/24 17:05:36 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	update_camera(t_camera *camera)
{
	camera->up_vector = normalize_vector(create_vector(camera->center,
				set_vector(camera->center.x, camera->center.y,
				camera->center.z + 1)));
	camera->u = cross_product(camera->up_vector, camera->direction);
	camera->u = normalize_vector(camera->u);
	camera->v = cross_product(camera->u, camera->direction);
	camera->v = normalize_vector(camera->v);
	camera->center = vector_add(camera->center, camera->direction);
	camera->u = scalar_prod(camera->u, SCREEN_WIDTH);
	camera->v = scalar_prod(camera->v, (SCREEN_WIDTH / ASPECT));
}

int	create_camera(char **info, t_scene *scene)
{
	t_camera	*camera;

	if (scene->camera || ft_array_len(info) != 3)
		return (0);
	camera = ft_calloc(sizeof(t_camera), 1);
	if (!camera)
		return (0); // malloc error
	if (get_point(info[1], &camera->coord))
		return (0);
	if (get_vector(info[2], &camera->direction))
		return (0);
	if (get_fov(info[3], &camera->fov);
		return (0);
	update_camera(camera);
	scene->camera = camera;
	return (1);
}
