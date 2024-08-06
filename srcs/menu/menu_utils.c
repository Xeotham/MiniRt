/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:44:07 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/06 08:45:45 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

size_t	get_actual_obj_nb(t_obj_list *obj, t_obj_list *list)
{
	size_t	count;

	count = 1;
	while (list->next && list != obj)
	{
		if (list != obj && list->obj_id == obj->obj_id)
			count++;
		list = list->next;
	}
	return (count);
}
