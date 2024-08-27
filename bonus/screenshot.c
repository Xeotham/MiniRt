/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:39:53 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/27 10:36:57 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

static int	open_screenshot_file(int nb)
{
	int		fd;
	char	*path;
	char	*name;

	fd = open("./Screenshots", O_RDONLY | __O_DIRECTORY);
	if (fd == -1)
		path = "Render_";
	else
		path = "./Screenshots/Render_";
	close(fd);
	name = join_and_free(path, ft_itoa(nb), 0, 1);
	name = join_and_free(name, ".ppm", 1, 0);
	if (!name)
		return (-1);
	fd = open(name, O_WRONLY | O_CREAT | O_EXCL, 0644);
	free(name);
	if (fd == -1)
		return (open_screenshot_file(++nb));
	return (fd);
}

static void	print_pixel(int color, int fd)
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;

	red = (color >> 24);
	green = (color >> 16);
	blue = (color >> 8);
	ft_fprintf(fd, "%d %d %d\n", red, green, blue);
}

static void	compute_scene(t_scene *scene, int fd)
{
	int			x;
	int			y;
	int			pixel_color;
	t_ray		ray;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ray = cast_ray(scene->camera, x, y);
			pixel_color = compute_pixel(ray, scene);
			print_pixel(pixel_color, fd);
			x++;
		}
		y++;
	}
}

void	take_screenshot(t_scene *scene)
{
	int	fd;

	fd = open_screenshot_file(0);
	if (fd == -1)
		return ;
	ft_fprintf(fd, "P3\n%d %d\n255\n", SCREEN_WIDTH, SCREEN_HEIGHT);
	compute_scene(scene, fd);
	close(fd);
}
