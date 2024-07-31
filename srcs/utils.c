/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:44:03 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/30 14:31:56 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_identifier	get_element_id(char *element)
{
	int			i;
	const char	*ids[7] = {"A", "C", "L", "sp", "pl", "cy", NULL};

	i = 0;
	while (ids[i])
	{
		if (!ft_strncmp(ids[i], element, ft_strlen(ids[i]) + 1))
			return (i);
		i++;
	}
	return (NO_ID);
}

int	ft_clamp(int min, int max, int value)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	else
		return (value);
}