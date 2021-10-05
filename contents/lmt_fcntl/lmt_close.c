#include <fcntl.h>
#include <stdlib.h>
#include "lmt_fcntl.h"

void	lmt_close(int fd)
{
	if (close(fd) == -1)
		exit(1);
}
