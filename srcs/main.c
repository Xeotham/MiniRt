/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:47:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/27 15:20:47 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int ac, char **av)
{
	t_scene	*scene;

	if (ac != 2)
		return (EXIT_FAILURE);
	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		destroy_scene(NULL, 0, ERR_MALLOC);
	create_scene(av[1], scene);
	//if (!get_obj_list(map, scene))
	//	return (EXIT_FAILURE);
}
