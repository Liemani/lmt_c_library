#ifndef LMT_FCNTL_H
# define LMT_FCNTL_H

# include <fcntl.h>

int	lmt_open(const char *path, int oflag, mode_t mode);
void	lmt_close(int fd);

#endif
