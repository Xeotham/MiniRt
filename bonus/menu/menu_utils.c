/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:44:07 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/13 19:09:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

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

void	print_gauge(int max, double value, char *color, char *value_name)
{
	double	load;
	double	i;

	i = 0;
	load = (20 * value) / max;
	if (value_name)
		printf("%s:\n", value_name);
	printf("╔════════════════════╗\n");
	printf("║%s", color);
	while (i < load)
	{
		printf("▓");
		i++;
	}
	while (i < 20)
	{
		printf(" ");
		i++;
	}
	printf("\033[0m║ %.0lf%% (%.2lf/%d)\n", ((100 * value) / max), value, max);
	printf("╚════════════════════╝\n");
}
