/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:10:19 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/21 14:15:21 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_objfind_id(t_obj_list *lst, t_identifier id)
{
	t_obj_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->obj_id == id)
			return (id);
		tmp = tmp->next;
	}
	return (0);
}
