/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeo <xeo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:58:05 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/11 22:15:08 by xeo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <parser.h>

static int	check_ids(char *id)
{
	int		i;
	char	*ids[7] = {"A", "C", "L", "sp", "pl", "cy", NULL};

	i = -1;
	while (ids[++i])
		if (!ft_strncmp(ids[i], id, ft_strlen(ids[i]) + 1))
			return (i);
	return (-1);
}

static int	sort_in_struct(char **info, t_minirt *minirt)
{
	t_identifier	id;
	int	(*obj_create[6]) (char **, t_minirt *) {}

	id = check_ids(info[0]);
	if (info == -1 || id == MRT_NO_ID)
		return (0);
	else if (!obj_create[id])
		
}

static int	*create_obj_node(char *obj, t_minirt *minirt)
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

int	get_obj_list(char **map, void *minirt)
{
	size_t	i;

	i = -1;
	if (!map || !(*map))
		return (NULL);
	while (map[++i])
		if (!create_obj_node(map[i], minirt))
			return (0);
	return (1);
}
