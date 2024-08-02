/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_object_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:03:28 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/02 15:07:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static const bool g_draw = true;
static const bool g_no_draw = false;
#define LIGHT	0
#define OBJ		1

static bool	change_actual_obj(keys_t key, t_obj_list **actual_obj, t_obj_list *objs)
{
	if (!(*actual_obj)
		|| (key == MLX_KEY_PERIOD && !(*actual_obj)->next))
	{
		(*actual_obj) = objs;
		print_actual_obj((*actual_obj), objs);
		return (g_no_draw);
	}
	else if (key == MLX_KEY_COMMA && !(*actual_obj)->prev)
	{
		(*actual_obj) = ft_objlast(objs);
		print_actual_obj((*actual_obj), objs);
		return (g_no_draw);
	}
	else if (key == MLX_KEY_PERIOD)
	{
		(*actual_obj) = (*actual_obj)->next;
		print_actual_obj((*actual_obj), objs);
		return (g_no_draw);
	}
	else if (key == MLX_KEY_COMMA)
	{
		(*actual_obj) = (*actual_obj)->prev;
		print_actual_obj((*actual_obj), objs);
		return (g_no_draw);
	}
	return (g_draw);
}

bool	modify_objs(keys_t key, t_obj_list *objs, mlx_t *display)
{
	static t_obj_list	*actual_obj = NULL;

	if (!change_actual_obj(key, &actual_obj, objs))
		return (g_no_draw);
	if ((actual_obj)->obj_id == ID_SPHERE)
		modify_sphere(key, &(actual_obj)->obj_struct, display);
	else if ((actual_obj)->obj_id == ID_PLANE)
		modify_plane(key, &(actual_obj)->obj_struct, display);
	else if ((actual_obj)->obj_id == ID_CYLINDER)
		modify_cylinder(key, &(actual_obj)->obj_struct, display);
	return (g_draw);
}


void	print_actual_obj(t_obj_list *obj, t_obj_list *list)
{
	size_t	count;

	count = 1;
	while (list->next && list != obj)
	{
		if (list != obj && list->obj_id == obj->obj_id)
			count++;
		list = list->next;
	}
	if (obj->obj_id == ID_SPHERE)
		printf("Currently modifying sphere number %zu.\n", count);
	else if (obj->obj_id == ID_PLANE)
		printf("Currently modifying plane number %zu.\n", count);
	else if (obj->obj_id == ID_CYLINDER)
		printf("Currently modifying cylinder number %zu\n", count);
}

void	check_axis_state(keys_t key, bool *axis)
{
	if (key == MLX_KEY_M)
	{
		(*axis) = !(*axis);
		if (*axis)
			printf("Axis modification unabled\n");
		else
			printf("Axis modification disabled\n");
	}
}

void	check_normal_state(keys_t key, bool *axis)
{
	if (key == MLX_KEY_M)
	{
		(*axis) = !(*axis);
		if (*axis)
			printf("Normal modification unabled\n");
		else
			printf("Normal modification disabled\n");
	}
}
