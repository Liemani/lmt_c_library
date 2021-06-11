#ifndef UTIL_H
# define UTIL_H

# define ALLOCATION_ERROR		1
# define READ_ERROR				2
# define WRITE_ERROR			3

void	exit_with_error(int exit_code);
void	*lmt_alloc(size_t size);
ssize_t	lmt_read(int fd, void *buffer, size_t size);
ssize_t	lmt_write(int fd, const char *string);
char	*lmt_realloc_string(char *string, size_t size);

#endif
