/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:26:02 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/24 16:02:56 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*static void	replace_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t' || line[i] == ',')
			line[i] = ' ';
		i++;
	}
}*/

t_identifier	get_element_id(char *element)
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

static int	parse_line(char *line, t_scene *scene)
{
	t_identifier	id;
	char			**info;
	int				(*element_create[6])(char **, t_scene *);

	info = ft_split(line, ' ');
	if (!info)
		return (0);
	element_create[ID_AMB_LIGHT] = create_amb_light;
	element_create[ID_CAMERA] = create_camera;
	element_create[ID_LIGHT] = create_point_light;
	element_create[ID_SPHERE] = create_sphere;
	element_create[ID_PLANE] = create_plane;
	element_create[ID_CYLINDER] = create_cylinder;
	id = get_element_id(info[0]);
	if (id == NO_ID || !element_create[id](info, scene))
		return (0);
	else
		return (1);
}

static char	*read_file(int fd, t_scene *scene)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, scene);
		line = get_next_line(fd);
	}
	return (final);
}

void	create_scene(char *file_name, t_scene *scene)
{
	int		fd;
	char	**args;
	char	*j_args;

	args = NULL;
	j_args = NULL;
	// if (ft_strrcmp(file_name, ".rt"))
	// 	return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL); // error
	j_args = read_file(fd);
	try_close(fd);
	if (!j_args)
		return (NULL);
	args = ft_split(j_args, '\n');
	free(j_args);
	if (!args)
		return (NULL);
	return (args);
}
