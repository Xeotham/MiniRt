/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:41 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/06/25 16:31:57 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*err_msg(int code)
{
	if (code == ERR_MALLOC || code == ERR_OPEN)
		return (strerror(errno));
	if (code == ERR_NO_ID)
		return ("Element identifier misconfigurated");
	if (code == ERR_CAM_NB)
		return ("There can be no more than one camera");
	if (code == ERR_CAM_INFO)
		return ("There must be four camera informations");
	if (code == ERR_CAM_COORD)
		return ("Camera point coordinates misconfigurated");
	if (code == ERR_CAM_DIR)
		return ("Camera orientation vector misconfigurated");
	if (code == ERR_CAM_FOV)
		return ("Camera field of view misconfigurated");
}

void	destroy_scene(t_scene *scene, int line_index, int code)
{
	free_scene(scene);
	ft_fprintf("Error\nLine: %d: %s\n", line_index, err_msg(code));
	exit (EXIT_FAILURE);
}
