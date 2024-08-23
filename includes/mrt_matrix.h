/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_matrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:58:08 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/12 15:05:30 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_MATRIX_H
# define MRT_MATRIX_H

# include <mrt_vector.h>
# include <stddef.h>
# include <stdbool.h>
# include <math.h>

# define PIE 3.14159265

typedef double**	t_matrix;

t_matrix	create_matrix(size_t x, size_t y);
t_matrix	copy_matrix(t_matrix matrix);
t_matrix	matrix_product(size_t matrix_nb, t_matrix matrix1, ...);
t_matrix	set_resize_matrix(double size_x, double size_y, double size_z);
t_matrix	set_translation_matrix(double t_x, double t_y, double t_z);
t_matrix	set_r_x_matrix(double teta);
t_matrix	set_r_y_matrix(double teta);
t_matrix	set_r_z_matrix(double teta);
bool		mat_vec_product(t_matrix matrix, t_vector3 *vector);
t_vector3	matrix_to_vector(t_matrix matrix);
void		identity_matrix(t_matrix matrix);
void		swap_rows(t_matrix matrix, int row1, int row2);
void		mult_to_row(t_matrix matrix[2], int row, double mult);
void		mult_and_add_to_row(t_matrix matrix[2], int row1,
				int row2, double mult);
int			is_identity(t_matrix matrix);
int			get_max_elem_row(t_matrix matrix, int collumn);

#endif
