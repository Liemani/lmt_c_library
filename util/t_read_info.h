#ifndef T_READ_INFO_H
# define T_READ_INFO_H

# include <sys/types.h>

#define READ_BUFFER_SIZE	1024

#define GET_TO_EOF			0
#define READS_LINE			1

typedef struct	s_read_info
{
	int			fd;
	char		buffer[READ_BUFFER_SIZE + 1];
	ssize_t		number_of_bytes_read;
	char		*p_cursor;
}				t_read_info;

t_read_info		*alloc_read_info(void);
void			init_read_info(t_rad_info *p_info, int fd);
t_read_info		*new_read_info(int fd);
void			free_read_info(t_rad_info *p_info);
int				get_line(t_read_info *p_read_info);

#endif
