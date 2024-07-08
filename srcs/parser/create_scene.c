/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:26:02 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/08 23:57:03 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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

static t_error	parse_line(char *line, t_scene *scene)
{
	t_identifier	id;
	t_error			error;
	char			**info;
	t_error			(*element_create[6])(char **, t_scene *);

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

void	check_scene_implementability(t_scene *scene, int line_index)
{
	if (!scene->camera)
		exit_scene(scene, line_index, ERR_NO_CAM);
	if (!scene->light)
		exit_scene(scene, line_index, ERR_NO_LIGHT);
}

void	create_scene(char *file_name, t_scene *scene)
{
	int		fd;
	t_error	error;
	char	*line;
	int		line_index;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_scene(scene, 0, ERR_OPEN);
	line_index = 0;
	error = ERR_EMPTY_FILE;
	line = get_next_line(fd);
	while (line)
	{
		error = parse_line(line, scene);
		free(line);
		line_index++;
		if (error)
			break ;
		line = get_next_line(fd);
	}
	close_file(fd);
	if (error)
		exit_scene(scene, line_index, error);
	check_scene_implementability(scene, line_index);
}
