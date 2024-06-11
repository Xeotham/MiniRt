/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeo <xeo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:28:01 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/11 20:07:40 by xeo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
/*================================== INCLUDES ================================*/

# include <MLX42.h>
# include <libft.h>
# include <math.h>
# include <mrt_vector.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_identifier
{
	MRT_NO_ID = -1,
	MRT_AMB_LIGHT,
	MRT_CAMERA,
	MRT_LIGHT,
	MRT_SPHERE,
	MRT_PLANE,
	MRT_CYLINDER
}	t_identifier;

typedef struct s_minirt
{
	mlx_t		mlx;
	t_camera	*camera;
	t_obj_list	**light;
	t_obj_list	**object;
}	t_minirt;

#endif