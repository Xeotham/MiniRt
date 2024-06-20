/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:58:05 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/20 16:27:34 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	check_ids(char *id)
{
	int			i;
	const char	*ids[7] = {"A", "C", "L", "sp", "pl", "cy", NULL};

	i = 0;
	while (ids[i])
	{
		if (!ft_strncmp(ids[i], id, ft_strlen(ids[i]) + 1))
			return (i);
		i++;
	}
	return (-1);
}

static int	sort_in_struct(char **info, t_scene *scene)
{
	t_identifier	id;
	int				(*element_create[6])(char **, t_scene *);

	element_create[ID_AMB_LIGHT] = create_amb_light;
	element_create[ID_CAMERA] = create_camera;
	element_create[ID_LIGHT] = create_point_light;
	element_create[ID_SPHERE] = create_sphere;
	element_create[ID_PLANE] = create_plane;
	element_create[ID_CYLINDER] = create_cylinder;
	id = check_ids(info[0]);
	if (id == NO_ID || !element_create[id](info, scene))
		return (0);
	else
		return (1);
}

static int	create_obj_node(char *obj, t_scene *scene)
{
	char	**info;
	int		error;

	info = ft_split(obj, ' ');
	if (!info)
		return (0); // malloc error
	error = sort_in_struct(info, scene);
	ft_free_2d_array(info, ft_array_len(info));
	return (error);
}

int	get_obj_list(char **map, t_scene *scene)
{
	size_t	i;

	i = 0;
	if (!map || !(*map))
		return (0);
	while (map[i])
	{
		if (!create_obj_node(map[i], scene))
			return (0);
		i++;
	}
	return (1);
}
