/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_read_info_method.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/13 16:36:27 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "t_read_info.h"
#include "util.h"
#include "libft.h"

/*
**	Return value:
**		TRUE: Reads a line
**		FALSE: Needs lmt_read()
*/

static int	append_until_nl(t_read_info *p_info)
{
	char	*p_end;
	int		get_to_nl;
	char	*p_append_end;
	size_t	line_len;
	size_t	append_size;

	p_end = p_info->buffer + p_info->reads_len;
	if (p_info->p_cursor >= p_end)
		return (FALSE);
	p_append_end = ft_strchr(p_info->p_cursor, '\n');
	if (p_append_end == NULL)
	{
		p_append_end = p_end;
		get_to_nl = FALSE;
	}
	else
		get_to_nl = TRUE;
	*p_append_end = '\0';
	line_len = p_info->p_line != NULL ? ft_strlen(p_info->p_line) : 0;
	append_size = (p_append_end - p_info->p_cursor) + 1;
	p_info->p_line = lmt_realloc_string(p_info->p_line, line_len + append_size);
	ft_memcpy(p_info->p_line + line_len, p_info->p_cursor, append_size);
	p_info->p_cursor = p_append_end + 1;
	return (get_to_nl);
}

/*
**	Description:
**		You don't need to free 'p_info->p_line'
**		If you freed it, set it to NULL
*/

int			read_info_get_line(t_read_info *p_info, char **pp_line)
{
	free(p_info->p_line);
	p_info->p_line = NULL;
	while (append_until_nl(p_info) == FALSE)
	{
		p_info->reads_len =
			lmt_read(p_info->fd, p_info->buffer, READ_BUFFER_SIZE);
		if (p_info->reads_len == 0)
			break ;
		p_info->p_cursor = p_info->buffer;
	}
	*pp_line = p_info->p_line;
	return (p_info->p_line ? READS_LINE : GET_TO_EOF);
}
