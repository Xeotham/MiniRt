/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:28:01 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/17 20:40:26 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
/*================================== INCLUDES ================================*/

# include <MLX42.h>
# include <libft.h>
# include <math.h>
# include <mrt_vector.h>
# include <stdlib.h>
# include <unistd.h>

/* ==== DEFINE ==== */

typedef enum e_identifier
{
	MRT_NO_ID = -1,
	MRT_AMB_LIGHT,
	MRT_CAMERA,
	MRT_LIGHT,
	MRT_SPHERE,
	MRT_PLANE,
	MRT_CYLINDER
}	t_identifier;

/* ==== STRUCT ==== */

typedef struct s_obj_list
{
	t_identifier		obj_id;
	void				*obj_struct;
	struct s_obj_list	*next;
}						t_obj_list;

typedef struct s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct s_camera
{
	t_vector3	coord;
	t_vector3	direction;
	int			fov;
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
	t_vector3		coord;
	double			diameter;
	t_color			color;
}					t_sphere;

typedef struct s_plane
{
	t_vector3		coord;
	t_vector3		normal;
	t_color			color;
}					t_plane;

typedef struct s_cylinder
{
	t_vector3		coord;
	t_vector3		axis;
	double			diameter;
	double			height;
	t_color			color;
	double			**matrix;
}					t_cylinder;

typedef struct s_minirt
{
	mlx_t		mlx;
	t_camera	*camera;
	t_obj_list	*light;
	t_obj_list	*object;
}	t_minirt;

/* ==== MAP ==== */

char					**get_map(char *file_name);

/* ==== UTILS ==== */

void					ft_objclear(t_obj_list **lst);
void					ft_objadd_back(t_obj_list **lst, t_obj_list *new);
t_obj_list				*ft_objlast(t_obj_list *lst);
int						ft_objfind_id(t_obj_list *lst, t_identifier id);

/* ==== LINK LIST ==== */

int						get_obj_list(char **map, t_minirt *minirt);

/* ==== COLOR ==== */

int					set_color(t_color *color, int red, int green, int blue);

/* ==== SET OBJECT ==== */

int	create_amb_light(char **info, t_minirt *minirt);
int	create_point_light(char **info, t_minirt *minirt);
int	create_camera(char **info, t_minirt *minirt);
int	create_sphere(char **info, t_minirt *minirt);
int	create_plane(char **info, t_minirt *minirt);
int	create_cylinder(char **info, t_minirt *minirt);

/* ==== UTILS ==== */

int	ft_check_range(double value, double min, double max);

#endif