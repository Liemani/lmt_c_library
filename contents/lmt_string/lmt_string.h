/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_string.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:02:52 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 19:28:57 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_STRING_H
# define LMT_STRING_H

# include <stddef.h>	// size_t

///	- property
///		- str: non-optional
typedef struct s_lmt_string
{
	char	*str;
	size_t	count;
}	t_lmt_string;

///	type function
t_lmt_string	*lmt_string_new(const char *value);
void			lmt_string_free(t_lmt_string *string);

///	method
t_lmt_string	*lmt_string_split(t_lmt_string *string, char *separator);

t_lmt_string	*lmt_string_remove_first(t_lmt_string *string, size_t count);
t_lmt_string	*lmt_string_remove_last(t_lmt_string *string, size_t count);

int				lmt_string_append_string(t_lmt_string *string, char *word);
int				lmt_string_append_lmt_string(
					t_lmt_string *string, t_lmt_string *word);

#endif
