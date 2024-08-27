/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:26:02 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 17:45:12 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static void	init_display(t_scene *scene)
{
	const bool	no_resize = false;
	const char	title[] = "miniRT";

	scene->display = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, title, no_resize);
	if (!scene->display)
		exit_scene(NULL, 0, ERR_MLX);
	scene->image = mlx_new_image(scene->display, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!scene->image)
		exit_scene(NULL, 0, ERR_MLX);
	mlx_image_to_window(scene->display, scene->image, 0, 0);
}

static void	check_scene_validity(t_scene *scene, int line_index)
{
	if (!scene->camera)
		exit_scene(scene, line_index, ERR_NO_CAM);
	if (!ft_objfind_id(scene->lights, ID_AMB_LIGHT))
		exit_scene(scene, line_index, ERR_NO_AMB_LIGHT);
	if (!ft_objfind_id(scene->lights, ID_LIGHT))
		exit_scene(scene, line_index, ERR_NO_LIGHT);
}

t_scene	*create_scene(char **argv)
{
	int		fd;
	t_error	error;
	t_scene	*scene;
	int		line_index;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		exit_scene(NULL, 0, ERR_MALLOC);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_scene(scene, 0, ERR_OPEN);
	error = read_file(fd, scene, &line_index);
	close_file(fd);
	if (error)
		exit_scene(scene, line_index, error);
	check_scene_validity(scene, line_index);
	scene->pixelation = 1;
	if (argv[2])
		scene->pixelation = ft_atoi(argv[2]);
	init_display(scene);
	return (scene);
}
