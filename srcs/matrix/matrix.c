/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:57:13 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/17 21:41:30 by mhaouas          ###   ########.fr       */
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
		matrix[i++][j++] = 1;
}

t_matrix	create_matrix(size_t x, size_t y)
{
	double	**matrix;
	size_t	i;

	i = -1;
	matrix = ft_calloc(sizeof(double *), x);
	if (!matrix)
		return (NULL);
	while (++i < x)
	{
		matrix[i] = ft_calloc(sizeof(double), y);
		if (!matrix[i])
		{
			ft_free_2d_array(matrix, i);
			return (NULL);
		}
	}
	return (matrix);
}

#include <stdio.h>

int	main(void)
{
	t_matrix	result;

	size_t	i;
	size_t	j;
	
	i = 0;
	printf("PIE : %f\n", PIE);
	result = matrix_product(3, set_translation_matrix(4, 4, 4), set_resize_matrix(8, 8, 8), set_r_y_matrix(PIE / 4));
	printf("matrix 1\n");
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f, ",result[i][j]);
			j++;
		}
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
}
