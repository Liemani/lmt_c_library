/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_double_linked_list.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:33 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/14 14:37:04 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_DOUBLE_LINKED_LIST_H
# define T_LMT_DOUBLE_LINKED_LIST_H

typedef struct s_lmt_double_linked_list
{
	void							*content;
	struct s_lmt_double_linked_list	*prev;
	struct s_lmt_double_linked_list	*next;
}	t_lmt_double_linked_list;

typedef void	(*t_free_content)(void *content);

//	type
t_lmt_double_linked_list	*lmt_double_linked_list_new(void *content);
void						lmt_double_linked_list_free_element(
								t_lmt_double_linked_list *element,
								t_free_content *free_content);
void						lmt_double_linked_list_free(
								t_lmt_double_linked_list *list,
								t_free_content *free_content);

//	method
void						lmt_double_linked_list_put_next(
								t_lmt_double_linked_list *list,
								t_lmt_double_linked_list *element);

#endif
