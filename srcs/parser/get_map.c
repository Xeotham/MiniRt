/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:26:02 by mhaouas           #+#    #+#             */
/*   Updated: 2024/05/24 11:00:41 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	replace_space(char *line)
{

}

char	*read_file(int fd)
{
	char	*file;
	char	*final;

	file = ft_calloc(1, 1);
	if (!file)
		return (NULL);
	final = ft_calloc(1, 1);
	if (!final)
	{
		free(file);
		return (NULL);
	}
	while (file)
	{
		final = join_and_free(final, file, 1, 1);
		file = get_next_line(fd);
	}
	return (final);
}

char	**get_map(char *file_name)
{
	int		fd;
	char	**args;
	char	*j_args;

	args = NULL;
	j_args = NULL;
	if (ft_strrcmp(file_name, ".rt"))
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL); //error
	j_args = read_file(fd);
	try_close(fd);
	if (!j_args)
		return (NULL);
	args = ft_split(j_args, '\n');
	if (!args)
		return (NULL);
	return (args);
}
