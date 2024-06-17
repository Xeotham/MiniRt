/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_matrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:58:08 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/17 21:36:43 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_MATRIX_H
# define MRT_MATRIX_H

# include <mrt_vector.h>
# include <stddef.h>
# include <math.h>

# define PIE 3.14159265

typedef double** t_matrix;

t_matrix	create_matrix(size_t x, size_t y);
t_matrix	matrix_product(size_t matrix_nb, t_matrix matrix1, ...);
t_matrix	set_resize_matrix(double size_x, double size_y, double size_z);
t_matrix	set_translation_matrix(double t_x, double t_y, double t_z);
t_matrix	set_r_x_matrix(double teta);
t_matrix	set_r_y_matrix(double teta);
t_matrix	set_r_z_matrix(double teta);
void		identity_matrix(t_matrix matrix);

#endif