/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:40:29 by xeo               #+#    #+#             */
/*   Updated: 2024/07/20 22:14:07 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*int	set_color(t_color *color, int red, int green, int blue)
{
	if ((0 > red || red > 255) || (0 > green || green > 255)
		|| (0 > blue || blue > 255))
		return (0);
	color->red = red;
	color->green = green;
	color->blue = blue;
	return (1);
}*/

int	set_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
