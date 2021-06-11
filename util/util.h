#ifndef UTIL_H
# define UTIL_H

void	*lmt_alloc(size_t size);
ssize_t	lmt_read(int fd, void *buffer, size_t size);
ssize_t	lmt_write(int fd, const char *string);
char	*lmt_realloc_string(char *string, size_t size);

#endif
