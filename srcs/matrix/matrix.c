/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:57:13 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/27 14:45:56 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mrt_matrix.h>
#include <minirt.h>

void	identity_matrix(t_matrix matrix)
{
	size_t	i;
	size_t	j;	

	i = 0;
	j = 0;
	while (i < 4 && j < 4)
	{
		matrix[i][j] = 1;
		i++;
		j++;
	}
}

t_matrix	create_matrix(size_t x, size_t y)
{
	double	**matrix;
	size_t	i;

	i = -1;
	matrix = ft_calloc(sizeof(double *), y);
	if (!matrix)
		return (NULL);
	while (++i < y)
	{
		matrix[i] = ft_calloc(sizeof(double), x);
		if (!matrix[i])
		{
			ft_free_2d_array(matrix, i);
			return (NULL);
		}
	}
	return (matrix);
}

t_vector3	matrix_to_vector(t_matrix matrix)
{
	t_vector3	vector;

	vector.x = matrix[0][0];
	vector.y = matrix[1][0];
	vector.z = matrix[2][0];
	ft_free_2d_array(matrix, 4);
	return (vector);
}
/*
#include <stdio.h>

int	main(void)
{
	t_matrix	result;
	t_vector3	vector;

	size_t	i;
	// size_t	j;
	
	i = 0;
	vector = set_vector(17, 17, 17);
	result = matrix_product(2, set_translation_matrix(4, 4, 4), set_resize_matrix(8, 8, 8));
	result = mat_vec_product(result, vector);
	printf("matrix 1\n");
	while (i < 4)
	{
		printf("%f, ",result[i][0]);
		printf("\n");
		i++;
	}
	i = 0;
	// printf("matrix 2\n");
	// while (i < 4)
	// {
	// 	j = 0;
	// 	while (j < 4)
	// 	{
	// 		printf("%f, ",matrix2[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
}*/
