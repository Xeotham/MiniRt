/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:47:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/12 11:35:49 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int ac, char **av)
{
	t_minirt	*minirt;

	if (ac != 2)
		return (1);
	minirt = ft_calloc(sizeof(t_minirt), 1);
	if (!minirt)
		return (1); //error
	if (!get_obj_list(get_map(av[1]), minirt))
		return (1);
}
