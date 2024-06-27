/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:58:02 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/27 14:44:30 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mrt_matrix.h>
#include <minirt.h>
#include <math.h>

t_matrix	set_resize_matrix(double size_x, double size_y, double size_z)
{
	t_matrix	matrix;

	matrix = create_matrix(4, 4);
	if (!matrix)
		return (NULL);
	identity_matrix(matrix);
	matrix[0][0] = size_x;
	matrix[1][1] = size_y;
	matrix[2][2] = size_z;
	return (matrix);
}

t_matrix	set_translation_matrix(double t_x, double t_y, double t_z)
{
	t_matrix	matrix;

	matrix = create_matrix(4, 4);
	if (!matrix)
		return (NULL);
	identity_matrix(matrix);
	matrix[0][3] = t_x;
	matrix[1][3] = t_y;
	matrix[2][3] = t_z;
	return (matrix);
}

t_matrix	set_r_x_matrix(double teta)
{
	t_matrix	matrix;

	matrix = create_matrix(4, 4);
	if (!matrix)
		return (NULL);
	identity_matrix(matrix);
	matrix[1][1] = cos(teta);
	matrix[1][2] = -sin(teta);
	matrix[2][1] = sin(teta);
	matrix[2][2] = cos(teta);
	return (matrix);
}

t_matrix	set_r_y_matrix(double teta)
{
	t_matrix	matrix;

	matrix = create_matrix(4, 4);
	if (!matrix)
		return (NULL);
	identity_matrix(matrix);
	matrix[0][0] = cos(teta);
	matrix[0][2] = sin(teta);
	matrix[2][0] = -sin(teta);
	matrix[2][2] = cos(teta);
	return (matrix);
}

t_matrix	set_r_z_matrix(double teta)
{
	t_matrix	matrix;

	matrix = create_matrix(4, 4);
	if (!matrix)
		return (NULL);
	identity_matrix(matrix);
	matrix[0][0] = cos(teta);
	matrix[0][1] = -sin(teta);
	matrix[1][0] = sin(teta);
	matrix[1][1] = cos(teta);
	return (matrix);
}
