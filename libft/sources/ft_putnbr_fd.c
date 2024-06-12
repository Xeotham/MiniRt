/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:33:16 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/05/01 18:15:25 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_number(unsigned long nbr, char to_print[10], int *i)
{
	if (nbr > 9)
		get_number(nbr / 10, to_print, i);
	to_print[*i] = nbr % 10 + '0';
	(*i)++;
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	int				i;
	char			to_print[10];

	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		write(fd, "-", 1);
	}
	i = 0;
	get_number(nbr, to_print, &i);
	write(fd, to_print, i);
}
