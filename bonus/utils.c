/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:44:03 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/08/26 13:41:12 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

int	ft_clamp(int min, int max, int value)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	else
		return (value);
}

double	ft_dclamp(double min, double max, double value)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	else
		return (value);
}

char	*get_line_trim(int fd, char *set)
{
	char	*str;
	char	*tmp;

	tmp = NULL;
	str = get_next_line(fd);
	if (str)
		tmp = ft_strtrim(str, set);
	if (!tmp)
		return (str);
	free(str);
	return (tmp);
}
