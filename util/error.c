#include <unistd.h>
#include <stdlib.h>
#include "error.h"

void	exit_with_error(int exit_code)
{
	write(2, "Error\n", 6);
	exit(exit_code);
}
