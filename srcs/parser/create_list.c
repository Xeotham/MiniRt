/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:58:05 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/27 15:25:08 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*static int	create_obj_node(char *obj, t_scene *scene)
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
}*/
