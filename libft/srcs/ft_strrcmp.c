/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:47:31 by mhaouas           #+#    #+#             */
/*   Updated: 2024/05/24 10:55:02 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strrcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (-1);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (i > 0 && j > 0)
	{
		if (s1[i] != s2[j])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i--;
		j--;
	}
	return (0);
}
