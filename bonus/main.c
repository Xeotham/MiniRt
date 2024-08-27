/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:47:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 17:23:58 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static bool	check_pixelation(char *pixelation, char *max)
{
	int			len;
	const int	len_max = ft_strlen(max);

	while (*pixelation == '0')
		pixelation++;
	len = ft_strlen(pixelation);
	while (ft_isdigit(*pixelation))
		pixelation++;
	if (*pixelation || len > len_max)
		return (true);
	if (len < len_max)
		return (false);
	if (ft_strncmp(pixelation, max, len_max) > 0)
		return (true);
	return (false);
}

static void	check_args(int ac, char **av)
{
	char	*max;

	if (ac == 1 || ac > 3)
	{
		ft_putstr_fd("Error\nThere must be one or two arguments.\n",
			STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	if (ft_strrncmp(av[1], ".rt", 3))
	{
		ft_putstr_fd("Error\nWrong file name extension.\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	if (!av[2])
		return ;
	max = ft_itoa(SCREEN_HEIGHT);
	if (!max)
		exit_scene(NULL, 0, ERR_MALLOC);
	if (check_pixelation(av[2], max))
	{
		ft_putstr_fd("Error\nPixelation incorrect.\n", STDERR_FILENO);
		free(max);
		exit (EXIT_FAILURE);
	}
	free(max);
}

int	main(int ac, char **av)
{
	t_scene	*scene;

	check_args(ac, av);
	scene = create_scene(av);
	print_menu(scene, NULL, NULL);
	draw_scene(scene, scene->pixelation);
	mlx_scroll_hook(scene->display, &mouse_scrolling, scene);
	mlx_key_hook(scene->display, &key_pressed, scene);
	mlx_close_hook(scene->display, &end_display, scene->display);
	mlx_loop(scene->display);
	destroy_scene(scene);
	printf("\033c");
	return (EXIT_SUCCESS);
}
