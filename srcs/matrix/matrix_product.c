/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:57:13 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/17 21:29:47 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <mrt_matrix.h>

static double	product_result(t_matrix matrix1, t_matrix matrix2, size_t ligne,
		size_t column)
{
	size_t	i;
	double	result;

	i = -1;
	result = 0;
	while (++i < 4)
		result += matrix1[column][i] * matrix2[i][ligne];
	return (result);
}

static t_matrix	do_matrix_product(t_matrix matrix1, t_matrix matrix2)
{
	size_t		i;
	size_t		j;
	t_matrix	result;

	i = 0;
	if (!matrix1 || !matrix2)
		return (NULL);
	result = create_matrix(4, 4);
	identity_matrix(result);
	if (!result)
		return (NULL);
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
			result[i][j] = product_result(matrix1, matrix2, j, i);
		i++;
	}
	ft_free_2d_array(matrix1, 4);
	return (result);
}

t_matrix	matrix_product(size_t matrix_nb, t_matrix matrix1, ...)
{
	size_t		i;
	va_list		matrix_lst;
	t_matrix	result;
	t_matrix	matrix2;

	i = 1;
	result = matrix1;
	va_start(matrix_lst, matrix1);
	while (i < matrix_nb)
	{
		matrix2 = (t_matrix)va_arg(matrix_lst, t_matrix);
		result = do_matrix_product(result, matrix2);
		ft_free_2d_array(matrix2, 4);
		i++;
	}
	va_end(matrix_lst);
	if (!result)
		return (NULL); // error
	return (result);
}
