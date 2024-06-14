/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_matrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:58:08 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/14 16:33:10 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_MATRIX_H
# define MRT_MATRIX_H

#include <mrt_vector.h>

typedef double** t_matrix;

t_matrix	create_matrix(size_t x, size_t y);
t_matrix	matrix_product(size_t matrix_nb, t_matrix matrix1, ...);
void		identity_matrix(t_matrix matrix);


#endif