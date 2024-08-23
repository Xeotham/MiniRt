/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 07:47:27 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/22 14:39:33 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mrt_matrix.h>
#include <minirt_bonus.h>

int	is_identity(t_matrix matrix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j && !doubles_are_equals(matrix[i][j], 1))
				return (0);
			else if (i != j && !doubles_are_equals(matrix[i][j], 0))
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	get_max_elem_row(t_matrix matrix, int collumn)
{
	size_t	i;
	int		max_elem_index;

	i = 1;
	max_elem_index = 0;
	while (i < 4)
	{
		if (fabs(matrix[collumn][i]) > fabs(matrix[collumn][max_elem_index]))
			max_elem_index = i;
		i++;
	}
	return (max_elem_index);
}
