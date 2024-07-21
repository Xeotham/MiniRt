/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 07:34:37 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/17 17:03:34 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mrt_matrix.h>
#include <minirt.h>
#include <libft.h>
#include <stdlib.h>

static void	row_math(t_matrix matrix[2], size_t row, size_t col)
{
	size_t	i;

	i = col + 1;
	while (i < 4)
	{
		if (matrix[0][row][i] != 0 && matrix[0][i][i] != 0)
			mult_and_add_to_row(matrix, i, row,\
				-(matrix[0][row][i] / matrix[0][i][i]));
		i++;
	}
}

static void	collumn_math(t_matrix matrix[2], size_t row, size_t col)
{
	size_t	i;

	i = row + 1;
	while (i < 4)
	{
		if (matrix[0][i][col] != 0 && matrix[0][col][col] != 0)
			mult_and_add_to_row(matrix, col, i,\
				-(matrix[0][i][col] / matrix[0][col][col]));
		i++;
	}
}

static void	do_calculs(t_matrix matrix[2], size_t row, size_t col)
{
	size_t	max_row;

	max_row = get_max_elem_row(matrix[0], col);
	if (max_row != row)
	{
		swap_rows(matrix[0], max_row, row);
		swap_rows(matrix[1], max_row, row);
	}
	if (matrix[0][col][row] != 1)
		mult_to_row(matrix, row, (1 / matrix[0][row][col]));
	collumn_math(matrix, row, col);
	row_math(matrix, row, col);
}

static int	format_matrix(t_matrix base, t_matrix inverse)
{
	size_t		i;
	t_matrix	matrix[2];
	static int	count = 0;

	matrix[0] = base;
	matrix[1] = inverse;
	i = 0;
	if (count == 100)
	{
		count = 0;
		return (0);
	}
	while (i < 4)
	{
		do_calculs(matrix, i, i);
		i++;
	}
	count++;
	return (1);
}


t_matrix	inverse_matrix(t_matrix matrix_to_inv)
{
	t_matrix	matrix_cp;
	t_matrix	inverse;

	matrix_cp = copy_matrix(matrix_to_inv);
	if (!matrix_cp)
		return (NULL);
	inverse = create_matrix(4, 4);
	if (!inverse)
	{
		free(matrix_cp);
		return (NULL);
	}
	identity_matrix(inverse);
	while (!is_identity(matrix_cp))
	{
		if (!format_matrix(matrix_cp, inverse))
		{
			ft_free_2d_array(matrix_cp, 4);
			ft_free_2d_array(inverse, 4);
			return (NULL);
		}
	}
	ft_free_2d_array(matrix_cp, 4);
	return (inverse);
}

#include <stdio.h>

int	main()
{
	t_matrix	test;
	t_matrix	test2;
	t_matrix	result;

	test = matrix_product(5, set_translation_matrix(10, 5, -8), set_resize_matrix(20, 20, 20), set_r_x_matrix(3.14), set_r_y_matrix(3.14), set_r_z_matrix(3.14));
	test2 = inverse_matrix(test);
	if (!test2)
		return (1);
	result = matrix_product(2, test, test2);
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
			printf("%f ", result[i][j]);
		printf("\n");
	}
	printf("\n");
}