/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:00:01 by mhaouas           #+#    #+#             */
/*   Updated: 2024/05/24 11:01:08 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <parser.h>

char	check_space(char a_char)
{
	int		i;
	char	*space;

	i = 0;
	space = IS_SPACE;
	while (space[i])
	{
		if (a_char == space[i])
			return (-1);
		i++;
	}
	return (a_char);
}