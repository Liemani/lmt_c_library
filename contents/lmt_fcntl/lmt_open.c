#include <fcntl.h>
#include <stdlib.h>
#include "lmt_fcntl.h"

int	lmt_open(const char *path, int oflag, mode_t mode)
{
	int	fd;
	fd = open(path, oflag, mode);
	if (fd == -1)
		exit(1);
	return (fd);
}
