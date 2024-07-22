/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:57:35 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/22 18:45:22 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	update_camera(t_camera *camera)
{
	camera->up_vector = set_vector(0, 0, 1);
	camera->u_screen = cross_product(camera->up_vector, camera->direction);
	camera->u_screen = normalize_vector(camera->u_screen);
	camera->v_screen = cross_product(camera->u_screen, camera->direction);
	camera->v_screen = normalize_vector(camera->v_screen);
	camera->screen_center = vector_add(camera->orig, camera->direction);
	camera->u_screen = scalar_prod(camera->u_screen, 1);
	camera->v_screen = scalar_prod(camera->v_screen, (1 / ASPECT));
}

t_error	create_camera(char **info, t_scene *scene)
{
	t_camera	*camera;

	if (scene->camera)
		return (ERR_CAM_NB);
	if (ft_array_len(info) != 4)
		return (ERR_CAM_INFO);
	camera = ft_calloc(sizeof(t_camera), 1);
	scene->camera = camera;
	if (!camera)
		return (ERR_MALLOC);
	if (get_point(info[1], &camera->orig))
		return (ERR_CAM_COORD);
	if (get_vector(info[2], &camera->direction))
		return (ERR_CAM_DIR);
	if (get_fov(info[3], &camera->fov))
		return (ERR_CAM_FOV);
	update_camera(camera);
	return (NO_ERR);
}
