/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeo <xeo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:24:32 by mhaouas           #+#    #+#             */
/*   Updated: 2024/06/11 20:19:44 by xeo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <libft.h>
# include <minirt.h>

/* ==== STRUCT ==== */

typedef struct s_obj_list
{
	t_identifier		obj_id;
	void				*obj_struct;
	struct s_obj_list	*next;
}						t_obj_list;

/* ==== MAP ==== */

char					**get_map(char *file_name);

/* ==== UTILS ==== */

void					ft_objclear(t_obj_list **lst);
void					ft_objadd_back(t_obj_list **lst, t_obj_list *new);
t_obj_list				*ft_objlast(t_obj_list *lst);
int						ft_objfind_id(t_obj_list **lst, t_identifier id);

/* ==== LINK LIST ==== */

int						get_obj_list(char **map, void *minirt);

#endif