/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:58:05 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/12 14:50:44 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	check_ids(char *id)
{
	int		i;
	const char	*ids[7] = {"A", "C", "L", "sp", "pl", "cy", NULL};

	i = -1;
	while (ids[++i])
		if (!ft_strncmp(ids[i], id, ft_strlen(ids[i]) + 1))
			return (i);
	return (-1);
}

static int	sort_in_struct(char **info, t_minirt *minirt)
{
	t_identifier	id;
	const int (*obj_create[6])(char **, t_minirt *) = {create_amb_light, create_camera,
		create_point_light, create_sphere, create_plane, create_cylinder};

	id = check_ids(info[0]);
	if (id == MRT_NO_ID || !obj_create[id](info, minirt))
		return (0);
	else
		return (1);
}

static int	create_obj_node(char *obj, t_minirt *minirt)
{
	char	**info;
	int		error;

	info = ft_split(obj, ' ');
	if (!info)
		return (0); // malloc error
	error = sort_in_struct(info, minirt);
	ft_free_2d_array(info, ft_array_len(info));
	return (error);
}

int	get_obj_list(char **map, t_minirt *minirt)
{
	size_t	i;

	i = -1;
	if (!map || !(*map))
		return (0);
	while (map[++i])
	{
		if (!create_obj_node(map[i], minirt))
			return (0);
	}
	return (1);
}
