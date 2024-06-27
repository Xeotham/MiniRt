/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:26:02 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/27 16:46:01 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	format_spaces(char *line)
{
	char *tmp;

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
	return (-1);
}

static t_error	parse_line(char *line, t_scene *scene)
{
	t_identifier	id;
	t_error			error;
	char			**info;
	t_error			(*element_create[6])(char **, t_scene *);

	format_spaces(line);
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
	if (id > NO_ID)
		error = element_create[id](info, scene);
	ft_free_2d_array(info, ft_array_len(info));
	if (id == NO_ID)
		return (ERR_NO_ID);
	return (error);
}

void	create_scene(char *file_name, t_scene *scene)
{
	int		fd;
	t_error	error;
	char	*line;
	int		line_index;

	// if (ft_strrcmp(file_name, ".rt"))
	// 	return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		destroy_scene(scene, 0, ERR_OPEN);
	error = NO_ERR;
	line_index = 1;
	line = get_next_line(fd);
	while (line)
	{
		error = parse_line(line, scene);
		free(line);
		if (error)
			break ;
		line_index++;
		line = get_next_line(fd);
	}
	close(fd);
	if (error)
		destroy_scene(scene, line_index, error);
}
