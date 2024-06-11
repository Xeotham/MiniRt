/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:06:09 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/11 10:58:02 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <minirt.h>


t_obj_list	*ft_objlast(t_obj_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_objadd_back(t_obj_list **lst, t_obj_list *new)
{
	t_obj_list	*tmp;

	if (!lst || !new)
		return ;
	else if (!(*lst))
		*lst = new;
	else
	{
		tmp = ft_objlast(*lst);
		tmp->next = new;
	}
}

void	ft_objclear(t_obj_list **lst)
{
	t_obj_list	*tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		if ((*lst)->obj_struct)
			free((*lst)->obj_struct);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
