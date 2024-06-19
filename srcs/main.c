/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:47:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/19 16:59:00 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int ac, char **av)
{
	t_scene	*scene;

	if (ac != 2)
		return (1);
	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (1); //error
	if (!get_obj_list(get_map(av[1]), scene))
		return (1);

}
