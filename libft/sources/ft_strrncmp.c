/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:28:08 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/07/08 23:53:03 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*area1;
	unsigned char	*area2;
	size_t			i;
	size_t			j;
	size_t			k;

	if (!s1 || !s2)
		return (0);
	area1 = (void *)s1;
	area2 = (void *)s2;
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	k = 0;
	while ((i - k >= 0) && (j - k >= 0) && (k < n))
	{
		if (area1[i - k] != area2[j - k])
			return (area1[i - k] - area2[j - k]);
		k++;
	}
	return (0);
}
