/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:14:44 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/17 09:08:12 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mrt_matrix.h>
#include <minirt.h>

void	swap_rows(t_matrix matrix, int row1, int row2)
{
	void	*tmp;

	tmp = matrix[row1];
	matrix[row1] = matrix[row2];
	matrix[row2] = tmp;
}

void	mult_to_row(t_matrix matrix[2], int row, double mult)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		matrix[0][row][i] *= mult;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		matrix[1][row][i] *=mult;
		i++;
	}
}

void	mult_and_add_to_row(t_matrix matrix[2], int row1, int row2, double mult)
{
	size_t	i;
	double	tmp;

	i = 0;
	tmp = 0;
	while (i < 4)
	{
		tmp = matrix[0][row1][i] * mult;
		matrix[0][row2][i] += tmp;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tmp = matrix[1][row1][i] * mult;
		matrix[1][row2][i] += tmp;
		i++;
	}
}
