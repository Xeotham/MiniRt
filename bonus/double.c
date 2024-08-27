/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:15:42 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 15:16:52 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>
#include <libft.h>
#include <stdbool.h>

double	double_abs(double nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

bool	doubles_equals(double a, double b)
{
	if (double_abs(a - b) <= double_abs(b / 1000))
		return (true);
	return (false);
}
