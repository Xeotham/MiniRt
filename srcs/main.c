/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:47:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/07/26 18:14:52 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	end_display(void *param)
{
	mlx_t	*display;

	display = (mlx_t *) param;
	mlx_close_window(display);
}

static void	key_pressed(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		end_display(param);
}

int	main(int ac, char **av)
{
	t_scene	*scene;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nThere must be one argument.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (ft_strrncmp(av[1], ".rt", 3))
		exit_scene(NULL, 0, ERR_FILE_NAME);
	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		exit_scene(NULL, 0, ERR_MALLOC);
	create_scene(av[1], scene);
	draw_scene(scene);
	mlx_key_hook(scene->display, &key_pressed, scene->display);
	mlx_close_hook(scene->display, &end_display, scene->display);
	mlx_loop(scene->display);
	destroy_scene(scene);
	return (EXIT_SUCCESS);
}
