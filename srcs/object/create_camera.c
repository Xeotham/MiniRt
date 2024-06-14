/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:57:35 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/13 10:09:24 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	create_camera(char **info, t_minirt *minirt)
{
	t_camera	*camera;

	if (minirt->camera || ft_array_len(info) != 8)
		return (0);
	camera = ft_calloc(sizeof(t_camera), 1);
	if (!camera)
		return (0); // malloc error
	camera->coord = set_vector(ft_atod(info[1]), ft_atod(info[2]),
			ft_atod(info[3]));
	camera->direction = set_vector(ft_atoi(info[4]), ft_atoi(info[5]),
			ft_atoi(info[6]));
	camera->fov = ft_atoi(info[7]);
	if (!ft_check_range(camera->direction.x, -1, 1)
		|| !ft_check_range(camera->direction.y, -1, 1)
		|| !ft_check_range(camera->direction.z, -1, 1)
		|| !ft_check_range(camera->fov, 0.0, 180.0))
	{
		free(camera);
		return (0);
	}
	minirt->camera = camera;
	return (1);
}
