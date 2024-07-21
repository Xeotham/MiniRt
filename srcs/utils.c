/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:44:03 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/20 19:44:19 by tde-la-r         ###   ########.fr       */
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
