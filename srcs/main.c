/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:47:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/11 16:19:11 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <parser.h>

int	main(int ac, char **av)
{
	t_minirt	*minirt;

	if (ac != 2)
		return (1);
	minirt = ft_calloc(sizeof(t_minirt), 1);
	if (!minirt)
		return (1); //error
	get_obj_list(get_map(av[1]), minirt);
	while (lst)
	{
		ft_printf("ids : %d, content : %p\n", lst->obj_id, lst->obj_struct);
		lst = lst->next;
	}
}
