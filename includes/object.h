/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeo <xeo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:21:15 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/11 21:46:51 by xeo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <minirt.h>
# include <mrt_vector.h>
# include <parser.h>

typedef struct s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct s_camera
{
	t_vector3		coord;
	t_vector3		direction;
	unsigned char	fov;
}					t_camera;

typedef struct s_point_light
{
	t_vector3		coord;
	double			brightness;
}					t_point_light;

typedef struct s_amb_light
{
	double			ratio;
	t_color			color;
}					t_amb_light;

typedef struct s_sphere
{
	t_identifier	id;
	t_vector3		coord;
	double			diameter;
	t_color			color;
}					t_sphere;

typedef struct s_plane
{
	t_identifier	id;
	t_vector3		coord;
	t_vector3		normal;
	t_color			color;
}					t_plane;

typedef struct s_cylinder
{
	t_identifier	id;
	t_vector3		coord;
	t_vector3		normal;
	double			diameter;
	double			height;
	t_color			color;
}					t_cylinder;

/* ==== COLOR ==== */
int					set_color(t_color *color, int red, int green, int blue);

#endif