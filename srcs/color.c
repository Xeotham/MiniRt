/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeo <xeo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:40:29 by xeo               #+#    #+#             */
/*   Updated: 2024/06/11 21:46:11 by xeo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <object.h>

int	set_color(t_color *color, int red, int green, int blue)
{
	if ((0 > red || red > 255) || (0 > green || green > 255) || (0 > blue
			|| blue > 255))
		return (0);
	color->red = red;
	color->green = green;
	color->blue = blue;
	return (1);
}
