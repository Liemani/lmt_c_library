/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_string_method.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:02:53 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 14:59:45 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_string.h"
#include "lmt_alloc.h"
#include "lmt_primitive_type.h"

t_lmt_string	*lmt_string_split(t_lmt_string *string, char *separator)
{
	char			*old_str;
	char			*first_separator;
	char			*tail_str;
	t_lmt_string	*head_string;

	if (!(string != NULL && separator != NULL))
		return (NULL);
	old_str = string->str;
	first_separator = lmt_str_first_str(old_str, separator);
	if (first_separator == NULL)
		return (NULL);
	*first_separator = '\0';
	head_string = lmt_string_new(old_str);
	tail_str = first_separator;
	while (*separator != '\0')
	{
		++separator;
		++tail_str;
	}
	lmt_string_init(string, tail_str);
	free(old_str);
	return (head_string);
}

t_lmt_string	*lmt_string_remove_first(t_lmt_string *string, size_t count)
{
	char			*old_str;
	char			*tail_str;
	t_lmt_string	*head_string;

	if (!(string != NULL && 0 < count && count <= string->count))
		return (NULL);
	old_str = string->str;
	tail_str = old_str + count;
	lmt_string_init(string, tail_str);
	*tail_str = '\0';
	head_string = lmt_string_new(old_str);
	free(old_str);
	return (head_string);
}

t_lmt_string	*lmt_string_remove_last(t_lmt_string *string, size_t count)
{
	char			*old_str;
	char			*tail_str;
	t_lmt_string	*head_string;

	if (!(string != NULL && 0 < count && count <= string->count))
		return (NULL);
	old_str = string->str;
	tail_str = old_str + (string->count - count);
	head_string = lmt_string_new(tail_str);
	*tail_str = '\0';
	lmt_string_init(string, old_str);
	free(old_str);
	return (head_string);
}

void	lmt_string_append_string(t_lmt_string *string, char *word)
{
	char	*old_str;
	size_t	word_count;
	char	*new_str;
	char	*check_point;

	if (!(string != NULL && word != NULL))
		return ;
	old_str = string->str;
	word_count = lmt_str_count(word);
	new_str = lmt_alloc(string->count + word_count + 1);
	check_point = new_str;
	check_point = lmt_strcpy(check_point, string->str);
	check_point = lmt_strcpy(check_point, word);
	*check_point = '\0';
	string->str = new_str;
	string->count += word_count;
	free(old_str);
}

void	lmt_string_append_lmt_string(t_lmt_string *string, t_lmt_string *word)
{
	char	*old_str;
	char	*new_str;
	char	*check_point;

	if (word == NULL)
		return ;
	old_str = string->str;
	new_str = lmt_alloc(string->count + word->count + 1);
	check_point = new_str;
	check_point = lmt_strcpy(check_point, string->str);
	check_point = lmt_strcpy(check_point, word->str);
	*check_point = '\0';
	string->str = new_str;
	string->count += word->count;
	free(old_str);
}
