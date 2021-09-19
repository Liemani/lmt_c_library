/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_realloc_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:38:38 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/19 14:02:36 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lmt_util.h"
#include "lmt_alloc.h"

char	*lmt_realloc_string(char *string, size_t size)
{
	char	*duplicated_string;
	size_t	length_of_string;
	size_t	size_to_copy;

	if (size == 0)
	{
		free(string);
		return (NULL);
	}
	duplicated_string = lmt_alloc(sizeof(char) * size);
	if (string == NULL)
	{
		*duplicated_string = '\0';
		return (duplicated_string);
	}
	length_of_string = lmt_unsafe_strlen(string);
	if (length_of_string <= size - 1)
		size_to_copy = length_of_string;
	else
		size_to_copy = size - 1;
	lmt_memcpy(duplicated_string, string, size_to_copy);
	free(string);
	duplicated_string[size_to_copy] = '\0';
	return (duplicated_string);
}
