/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:31:51 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/13 19:09:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

bool	type_to_move(keys_t key, action_t action, bool *light, bool *object)
{
	if (action != MLX_PRESS)
		return (true);
	if (key == MLX_KEY_L && ((*light) == false && (*object) == true))
		(*object) = false;
	else if (key == MLX_KEY_O && (((*object) == false && (*light) == true)))
		(*light) = false;
	if (key == MLX_KEY_L)
		(*light) = !(*light);
	else if (key == MLX_KEY_O)
		(*object) = !(*object);
	if (key == MLX_KEY_L && (*light) == true)
		printf("Light mod unabled.\n");
	else if (key == MLX_KEY_L && (*light) == false)
		printf("Light mod disabled.\n");
	if (key == MLX_KEY_O && (*object) == true)
		printf("Object mod unabled.\n");
	else if (key == MLX_KEY_O && (*object) == false)
		printf("Object mod disabled.\n");
	return (true);
}
