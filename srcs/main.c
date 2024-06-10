/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:47:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/05/24 11:00:37 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <parser.h>

int	main(int ac, char **av)
{
	char	**map;
	
	map = NULL;
	if (ac != 2)
		return (1);
	map = get_map(av[1]);
	int	i = 0;

	while (map[i])
		ft_printf("%s\n", map[i++]);
}