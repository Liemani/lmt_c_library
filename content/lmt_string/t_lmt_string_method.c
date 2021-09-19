#include <stdlib.h>
#include "t_lmt_string.h"
#include "lmt_unsafe.h"

t_lmt_string	*lmt_string_split(t_lmt_string *string, char *separator)
{
	char			*value;
	char			*first_separator;
	t_lmt_string	*head_string;

	value = string->value;
	first_separator = lmt_unsafe_strchr(value, separator);
	if (first_separator == NULL)
		return (NULL);
	*first_separator = '\0';
	head_string = lmt_string_new(value);
	while (*separator != '\0')
	{
		++first_separator;
		++separator;
	}
	lmt_string_init(string, first_separator);
	free(value);
	return (head_string);
}
