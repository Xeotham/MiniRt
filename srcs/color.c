/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:40:29 by xeo               #+#    #+#             */
/*   Updated: 2024/06/12 11:34:37 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	set_color(t_color *color, int red, int green, int blue)
{
	if ((0 > red || red > 255) || (0 > green || green > 255)
		|| (0 > blue || blue > 255))
		return (0);
	color->red = red;
	color->green = green;
	color->blue = blue;
	return (1);
}
