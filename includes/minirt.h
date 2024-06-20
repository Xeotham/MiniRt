/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:28:01 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/20 16:24:47 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
/*================================== INCLUDES ================================*/

# include <MLX42.h>
# include <libft.h>
# include <math.h>
# include <mrt_matrix.h>
# include <mrt_vector.h>
# include <fcntl.h>

/* ==== DEFINE ==== */

typedef enum e_identifier
{
	NO_ID = -1,
	ID_AMB_LIGHT,
	ID_CAMERA,
	ID_LIGHT,
	ID_SPHERE,
	ID_PLANE,
	ID_CYLINDER
}						t_identifier;

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define ASPECT (16.0 / 9.0)

/* ==== STRUCT ==== */

typedef struct s_obj_transform
{
	double				resize_x;
	double				resize_y;
	double				resize_z;
	double				translate_x;
	double				translate_y;
	double				translate_z;
	double				teta_x;
	double				teta_y;
	double				teta_z;
}						t_obj_transform;

typedef struct s_obj_list
{
	t_identifier		obj_id;
	void				*obj_struct;
	struct s_obj_list	*next;
}						t_obj_list;

typedef struct s_color
{
	double				red;
	double				green;
	double				blue;
}						t_color;

typedef struct s_camera
{
	t_vector3			coord;
	t_vector3			direction;
	t_vector3			up_vector;
	t_vector3			u;
	t_vector3			v;
	t_vector3			center;
	int					fov;
}						t_camera;

typedef struct s_point_light
{
	t_vector3			coord;
	double				brightness;
}						t_point_light;

typedef struct s_amb_light
{
	double				ratio;
	t_color				color;
}						t_amb_light;

typedef struct s_sphere
{
	t_vector3			coord;
	double				diameter;
	t_color				color;
}						t_sphere;

typedef struct s_plane
{
	t_vector3			coord;
	t_vector3			normal;
	t_color				color;
}						t_plane;

typedef struct s_cylinder
{
	t_vector3			coord;
	t_vector3			axis;
	double				diameter;
	double				height;
	t_color				color;
}						t_cylinder;

typedef struct s_scene
{
	mlx_t				mlx;
	t_camera			*camera;
	t_obj_list			*light;
	t_obj_list			*object;
}						t_scene;

/* ==== MAP ==== */

char					**get_map(char *file_name);

/* ==== UTILS ==== */

void					ft_objclear(t_obj_list **lst);
void					ft_objadd_back(t_obj_list **lst, t_obj_list *new);
t_obj_list				*ft_objlast(t_obj_list *lst);
int						ft_objfind_id(t_obj_list *lst, t_identifier id);

/* ==== LINK LIST ==== */

int						get_obj_list(char **map, t_scene *scene);

/* ==== COLOR ==== */

int						set_color(t_color *color, int red, int green, int blue);

/* ==== SET OBJECT ==== */

int						create_amb_light(char **info, t_scene *scene);
int						create_point_light(char **info, t_scene *scene);
int						create_camera(char **info, t_scene *scene);
int						create_sphere(char **info, t_scene *scene);
int						create_plane(char **info, t_scene *scene);
int						create_cylinder(char **info, t_scene *scene);
void					update_camera(t_camera *camera);

/* ==== UTILS ==== */

int						ft_check_range(double value, double min, double max);

#endif
