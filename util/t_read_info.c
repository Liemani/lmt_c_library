#include <unistd.h>
#include "t_read_info.h"
#include "util.h"
#include "libft.h"
#include "bool.h"

t_read_info	*alloc_read_info(void)
{
	t_read_info	*p_info;

	p_info = lmt_alloc(sizeof(t_read_info));
	return (p_info);
}

void		init_read_info(t_read_info *p_info, int fd)
{
	p_info->fd = fd;
	p_info->buffer[READ_BUFFER_SIZE] = '\0';
	p_info->number_of_bytes_read = 0;
	p_info->p_cursor = p_info->buffer;
}

t_read_info	*new_read_info(int fd)
{
	t_read_info	*p_info;

	p_info = alloc_read_info();
	init_read_info(p_info, fd);
	return (p_info);
}

void		free_read_info(t_read_info *p_info)
{
	free(p_info);
}

/*
**	Return value:
**		TRUE: Reads a line
**		FALSE: Needs lmt_read()
*/

static int	append_until_nl(t_read_info *p_info, char **pp_line_read)
{
	char	*p_end;
	int		get_to_nl;
	char	*p_append_end;
	size_t	length_of_line_read;

	p_end = p_info->buffer + p_info->number_of_bytes_read;
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
	length_of_line_read = ft_strlen(*pp_line_read);
	*pp_line_read = lmt_realloc_string(*pp_line_read, length_of_line_read + (p_append_end - p_info->cursor) + 1);
	memcpy(*ppline_read + length_of_line_read, p_info->cursor, p_append_end - p_info->cursor + 1);
	p_info->cursor = p_append_end + 1;
	return (get_to_nl);
}

/*
**	Description:
**		You don't need to free '*pp_line_read'
**		If you freed it, set it to NULL
**		If you stop calling get_line() before EOF, have to free *pp_line_read
*/

int			get_line(t_read_info *p_info, char **pp_line_read)
{
	free(*pp_line_read);
	*pp_line_read = NULL;
	while (append_until_nl(p_info, pp_line_read) == FALSE)
	{
		p_info->number_of_bytes_read = lmt_read(p_info->fd, p_info->buffer, READ_BUFFER_SIZE);
		if (p_info->number_of_bytes_read == 0)
			if (*pp_line_read != NULL)
				return (READS_LINE);
			else
				return (GET_TO_EOF);
		p_info->p_cursor = p_info->buffer;
	}
	return (READS_LINE);
}
