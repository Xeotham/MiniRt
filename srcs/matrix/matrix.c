/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:57:13 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/14 16:32:36 by mhaouas          ###   ########.fr       */
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

static t_matrix	do_matrix_product(t_matrix matrix1, t_matrix matrix2)
{
	size_t		i;
	size_t		j;
	t_matrix	result;

	i = 0;
	if (!matrix1)
		return (NULL);
	result = create_matrix(4, 4);
	identity_matrix(result);
	if (!result)
		return (NULL);
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
			result[i][j] = matrix1[i][j] * matrix2[j][i];
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

	i = 0;
	result = matrix1;
	va_start(matrix_lst, matrix1);
	while (i < matrix_nb)
	{
		matrix2 = (t_matrix)va_arg(matrix_lst, t_matrix);
		result = do_matrix_product(result, matrix2);
		ft_free_2d_array(matrix2, 4);
		i++;
	}
	if (!result)
		return (NULL); //error
	return (result);
}

#include <stdio.h>

int	main(void)
{
	double	**matrix1;
	double	**matrix2;

	size_t	i;
	size_t	j;
	
	i = 0;
	matrix1 = create_matrix(4, 4);
	matrix2 = create_matrix(4, 4);
	identity_matrix(matrix1);
	identity_matrix(matrix2);
	printf("matrix 1\n");
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f, ",matrix1[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	printf("matrix 2\n");
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f, ",matrix2[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
