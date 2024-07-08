/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:47:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/08 23:55:49 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int ac, char **av)
{
	t_scene	*scene;

	if (ac != 2)
		return (EXIT_FAILURE);
	if (ft_strrncmp(av[1], ".rt", 3))
		exit_scene(NULL, 0, ERR_FILE_NAME);
	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		exit_scene(NULL, 0, ERR_MALLOC);
	create_scene(av[1], scene);
	destroy_scene(scene);
	return (EXIT_SUCCESS);
}
