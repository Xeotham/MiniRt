/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:41 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/08/26 17:36:08 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static char	*err_msg2(t_error code, char *msg[37])
{
	msg[ERR_SP_INFO] = "There must be four sphere informations";
	msg[ERR_SP_COORD] = "Sphere coordinates misconfigurated";
	msg[ERR_SP_DIAM] = "Sphere diameter misconfigurated";
	msg[ERR_SP_COLOR] = "Sphere color misconfigurated";
	msg[ERR_CYL_INFO] = "There must be six cylinder informations";
	msg[ERR_CYL_COORD] = "Cylinder coordinates misconfigurated";
	msg[ERR_CYL_AXIS] = "Cylinder axis vector misconfigurated";
	msg[ERR_CYL_DIAM] = "Cylinder diameter misconfigurated";
	msg[ERR_CYL_HGT] = "Cylinder height misconfigurated";
	msg[ERR_CYL_COLOR] = "Cylinder color misconfigurated";
	msg[ERR_NO_CAM] = "Scene cannot be displayed without camera";
	msg[ERR_NO_LIGHT] = "Scene cannot be displayed without any kind of light";
	msg[ERR_NO_AMB_LIGHT] = "Scene cannot be displayed without ambient light";
	msg[ERR_EMPTY_FILE] = "Empty file";
	msg[ERR_FILE_NAME] = "";
	msg[ERR_MLX] = (char *) mlx_strerror(mlx_errno);
	return (msg[code]);
}

static char	*err_msg(t_error code)
{
	char	*msg[37];

	if (code > ERR_PL_COLOR)
		return (err_msg2(code, msg));
	msg[ERR_MALLOC] = strerror(errno);
	msg[ERR_OPEN] = strerror(errno);
	msg[ERR_NO_ID] = "Element identifier misconfigurated";
	msg[ERR_CAM_NB] = "There can be no more than one camera";
	msg[ERR_CAM_INFO] = "There must be four camera informations";
	msg[ERR_CAM_COORD] = "Camera point coordinates misconfigurated";
	msg[ERR_CAM_DIR] = "Camera orientation vector misconfigurated";
	msg[ERR_CAM_FOV] = "Camera field of view misconfigurated";
	msg[ERR_ALGT_NB] = "There can be no more than one ambient lightning";
	msg[ERR_ALGT_INFO] = "There must be three ambient lightning informations";
	msg[ERR_ALGT_RATIO] = "Ambient lightning ratio misconfigurated";
	msg[ERR_ALGT_COLOR] = "Ambient lightning color misconfigurated";
	msg[ERR_LGT_NB] = "There can be no more than one light point";
	msg[ERR_LGT_INFO] = "There must be three light point informations";
	msg[ERR_LGT_COORD] = "Light point coordinates misconfigurated";
	msg[ERR_LGT_RATIO] = "Light point ratio misconfigurated";
	msg[ERR_PL_INFO] = "There must be four plane informations";
	msg[ERR_PL_COORD] = "Plane coordinates misconfigurated";
	msg[ERR_PL_NORM] = "Plane normal vector misconfigurated";
	msg[ERR_PL_COLOR] = "Plane color misconfigurated";
	return (msg[code]);
}

void	destroy_scene(t_scene *scene)
{
	if (!scene)
		return ;
	ft_destroy_ptr(scene->camera, &free);
	ft_objclear(&scene->objects);
	ft_objclear(&scene->lights);
	if (scene->image)
		mlx_delete_image(scene->display, scene->image);
	if (scene->display)
		mlx_terminate(scene->display);
	free(scene);
	scene = NULL;
}

void	exit_scene(t_scene *scene, int line_index, int code)
{
	destroy_scene(scene);
	ft_fprintf(STDERR_FILENO, "Error\n");
	if (code >= ERR_NO_ID && code <= ERR_CYL_COLOR)
		ft_fprintf(STDERR_FILENO, "Line %d: ", line_index);
	ft_fprintf(STDERR_FILENO, "%s\n", err_msg(code));
	exit (EXIT_FAILURE);
}
