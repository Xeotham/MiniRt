/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:28:01 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/02 14:19:51 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
/*================================== INCLUDES ================================*/

# include <MLX42.h>
# include <libft.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <mrt_matrix.h>
# include <mrt_vector.h>
# include <fcntl.h>
# include <stdio.h>

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

typedef enum e_error
{
	NO_ERR,
	ERR_MALLOC,
	ERR_OPEN,
	ERR_NO_ID,
	ERR_CAM_NB,
	ERR_CAM_INFO,
	ERR_CAM_COORD,
	ERR_CAM_DIR,
	ERR_CAM_FOV,
	ERR_ALGT_NB,
	ERR_ALGT_INFO,
	ERR_ALGT_RATIO,
	ERR_ALGT_COLOR,
	ERR_LGT_NB,
	ERR_LGT_INFO,
	ERR_LGT_COORD,
	ERR_LGT_RATIO,
	ERR_PL_INFO,
	ERR_PL_COORD,
	ERR_PL_NORM,
	ERR_PL_COLOR,
	ERR_SP_INFO,
	ERR_SP_COORD,
	ERR_SP_DIAM,
	ERR_SP_COLOR,
	ERR_CYL_INFO,
	ERR_CYL_COORD,
	ERR_CYL_AXIS,
	ERR_CYL_DIAM,
	ERR_CYL_HGT,
	ERR_CYL_COLOR,
	ERR_NO_CAM,
	ERR_NO_LIGHT,
	ERR_EMPTY_FILE,
	ERR_FILE_NAME,
	ERR_MLX
}t_error;

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

typedef struct	s_ray
{
	t_vector3	origin;
	t_vector3	dest;
	t_vector3	dir;
}				t_ray;

typedef struct s_obj_list
{
	t_identifier		obj_id;
	void				*obj_struct;
	struct s_inter		(*test_inter)(t_ray, void*);
	struct s_obj_list	*prev;
	struct s_obj_list	*next;
}						t_obj_list;


typedef struct s_color
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	double	d_red;
	double	d_green;
	double	d_blue;
}						t_color;

typedef struct	s_inter
{
	t_vector3		point;
	t_vector3		normal;
	double			distance;
	t_obj_list		*element;
	t_color			color;
}					t_inter;

typedef struct s_camera
{
	t_vector3			orig;
	t_vector3			direction;
	t_vector3			u_screen;
	t_vector3			v_screen;
	t_vector3			screen_center;
	int					fov;
}						t_camera;

typedef struct s_point_light
{
	t_vector3			coord;
	double				ratio;
}						t_point_light;

typedef struct s_amb_light
{
	double			ratio;
	t_color			color;
}						t_amb_light;

typedef struct s_sphere
{
	t_vector3		coord;
	double			radius;
	t_color			color;
	t_obj_transform	*matrix;
}						t_sphere;

typedef struct s_plane
{
	t_vector3		coord;
	t_vector3		normal;
	t_color			color;
	t_obj_transform	*matrix;
}						t_plane;

typedef struct s_cylinder
{
	t_vector3		coord;
	t_vector3		axis;
	double			radius;
	double			height;
	t_color			color;
	t_obj_transform	*matrix;
}						t_cylinder;

typedef struct s_scene
{
	mlx_t		*display;
	mlx_image_t	*image;
	t_camera	*camera;
	t_obj_list	*lights;
	t_obj_list	*objects;
	int			pixelation;
}						t_scene;

/* ==== MAP ==== */

t_scene	*create_scene(char **argv);

/* ==== UTILS ==== */

void					ft_objclear(t_obj_list **lst);
void					ft_objadd_back(t_obj_list **lst, t_obj_list *new);
t_obj_list				*ft_objlast(t_obj_list *lst);
t_obj_list				*ft_objfind_id(t_obj_list *lst, t_identifier id);
void	set_prev(t_obj_list *lst, t_obj_list *actual_prev);

/* ==== LINK LIST ==== */

int						get_obj_list(char **map, t_scene *scene);

/* ==== COLOR ==== */
int	set_rgba(int r, int g, int b, int a);

/* ==== SET OBJECT ==== */

t_error					create_amb_light(char **info, t_scene *scene);
t_error					create_point_light(char **info, t_scene *scene);
t_error					create_camera(char **info, t_scene *scene);
t_error					create_sphere(char **info, t_scene *scene);
t_error					create_plane(char **info, t_scene *scene);
t_error					create_cylinder(char **info, t_scene *scene);
void					update_camera(t_camera *camera);


/* ==== UTILS ==== */

int		ft_clamp(int min, int max, int value);
double	ft_dclamp(double min, double max, double value);
void	create_double_color(t_color *color);
void	exit_scene(t_scene *scene, int line_index, int code);
void	destroy_scene(t_scene *scene);

/* ==== PARSER ==== */

bool	get_light_ratio(char *ratio, double *result);
bool	get_color(char *color, t_color *result);
bool	get_point(char *point, t_vector3 *vector);
bool	get_vector(char *vector, t_vector3 *result);
bool	get_fov(char *fov, int *result);
bool	get_measure(char *measure, double *result);

/* ==== DOUBLE ==== */

bool	doubles_equals(double a, double b);
double	double_abs(double nb);

/* ==== RAY ==== */

t_ray   create_ray(t_vector3 point_1, t_vector3 point_2);
t_ray	cast_ray(t_camera *camera, double coord_x, double coord_y);

/* ==== LIGHT ==== */

int 	light_test_inter(t_inter poi, t_obj_list *lights, t_obj_list *objects);
bool	test_shadow(t_ray int_to_light, t_inter poi, t_obj_list *objs);
t_color	compute_amb_light(t_obj_list *lights);
t_color	compute_point_light(double angle, t_obj_list *lights);


/* ==== SPHERE INTERSECTION ====*/

t_inter		test_sphere(t_ray ray, void *element);

/* ==== PLANE INTERSECTION ==== */

t_inter		test_plane(t_ray ray, void *element);

/* ==== CYLINDER INTERSECTION ====*/

t_inter		test_cylinder(t_ray ray, void *element);
double		test_cylinder_height(t_ray ray, t_cylinder *cylinder, double t);
void		swap_double(double *to_swap_1, double *to_swap_2);
double		compute_cap(t_ray ray, t_cylinder *cylinder, t_vector3 *normal);

t_vector3	compute_poi(t_ray ray, double distance);

/* ==== HOOKS ====*/
void	end_display(void *param);
void	key_pressed(mlx_key_data_t keydata, void *param);
void	mouse_scrolling(double xdelta, double ydelta, void* param);
bool	rotate_key(keys_t key, t_camera *camera, mlx_t *display);
bool	modify_lights(keys_t key, t_obj_list *lights, mlx_t *display);
void	modify_sphere(keys_t key, void **ptr, mlx_t *display);
void	modify_cylinder(keys_t key, void **ptr, mlx_t *display);
void	modify_plane(keys_t key, void **ptr, mlx_t *display);
void	check_axis_state(keys_t key, bool *axis);
void	check_normal_state(keys_t key, bool *axis);
bool	change_fov(keys_t key, t_camera *camera);
bool	change_pixelation(keys_t key, int *pixelation);
bool	translate_cam_hold(keys_t key, t_camera *camera);
bool	translate_cam_press(keys_t key, t_camera *camera);
bool	type_to_move(keys_t key, action_t action, bool *light, bool *object);
void	print_actual_obj(t_obj_list *obj, t_obj_list *list);
bool	modify_objs(keys_t key, t_obj_list *objs, mlx_t *display);

void	draw_scene(t_scene *scene, int pixelation);

#endif
