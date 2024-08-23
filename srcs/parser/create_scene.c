/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:26:02 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/22 23:43:15 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_identifier	get_element_id(char *element)
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

static void	format_spaces(char *line)
{
	char	*tmp;

	tmp = ft_strchr(line, '\t');
	while (tmp)
	{
		*tmp = ' ';
		tmp = ft_strchr(tmp, '\t');
	}
	tmp = ft_strrchr(line, '\n');
	if (tmp)
		*tmp = 0;
}

static t_error	parse_line(char *line, t_scene *scene)
{
	t_identifier	id;
	t_error			error;
	char			**info;
	t_error 		(*element_create[6])(char **, t_scene *);

	format_spaces(line);
	if (!*line)
		return (NO_ERR);
	info = ft_split(line, ' ');
	if (!info)
		return (ERR_MALLOC);
	element_create[ID_AMB_LIGHT] = create_amb_light;
	element_create[ID_CAMERA] = create_camera;
	element_create[ID_LIGHT] = create_point_light;
	element_create[ID_SPHERE] = create_sphere;
	element_create[ID_PLANE] = create_plane;
	element_create[ID_CYLINDER] = create_cylinder;
	id = get_element_id(info[0]);
	if (id != NO_ID)
		error = element_create[id](info, scene);
	ft_free_2d_array(info, ft_array_len(info));
	if (id == NO_ID)
		return (ERR_NO_ID);
	return (error);
}

static void	close_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static t_error	read_file(int fd, t_scene *scene, int *line_index)
{
	t_error	error;
	char	*line;

	*line_index = 0;
	error = ERR_EMPTY_FILE;
	line = get_line_trim(fd, "\a\b\t\n\v\f\r ");
	while (line)
	{
		error = parse_line(line, scene);
		free(line);
		(*line_index)++;
		if (error)
			return (error);
		line = get_line_trim(fd, "\a\b\t\n\v\f\r ");
	}
	if (error == NO_ERR)
	{
		if (scene->objects)
			set_prev(scene->objects, NULL);
		if (scene->lights)
			set_prev(scene->lights, NULL);
	}
	return (error);
}

static void	init_display(t_scene *scene)
{
	const bool	no_resize = false;
	const char	title[] = "miniRT";

	scene->display = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, title, no_resize);
	if (!scene->display)
		exit_scene(NULL, 0, ERR_MLX);
	scene->image = mlx_new_image(scene->display, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!scene->image)
		exit_scene(NULL, 0, ERR_MLX);
	mlx_image_to_window(scene->display, scene->image, 0, 0);
}

t_scene	*create_scene(char **argv)
{
	int		fd;
	t_error	error;
	t_scene	*scene;
	int		line_index;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		exit_scene(NULL, 0, ERR_MALLOC);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_scene(scene, 0, ERR_OPEN);
	error = read_file(fd, scene, &line_index);
	close_file(fd);
	if (error)
		exit_scene(scene, line_index, error);
	if (!scene->camera)
		exit_scene(scene, line_index, ERR_NO_CAM);
	if (!scene->lights)
		exit_scene(scene, line_index, ERR_NO_LIGHT);
	scene->pixelation = 1;
	if (argv[2])
		scene->pixelation = ft_atoi(argv[2]);
	init_display(scene);
	return (scene);
}
