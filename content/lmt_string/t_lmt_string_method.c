#include <stdlib.h>
#include "t_lmt_string.h"
#include "lmt_alloc.h"
#include "lmt_unsafe.h"

t_lmt_string	*lmt_string_split(t_lmt_string *string, char *separator)
{
	char			*old_value;
	char			*first_separator;
	t_lmt_string	*head_string;

	old_value = string->value;
	first_separator = lmt_unsafe_strchr(old_value, separator);
	if (first_separator == NULL)
		return (NULL);
	*first_separator = '\0';
	head_string = lmt_string_new(old_value);
	while (*separator != '\0')
	{
		++first_separator;
		++separator;
	}
	lmt_string_init(string, first_separator);
	free(old_value);
	return (head_string);
}

void			lmt_string_append_string(t_lmt_string *string, char *word)
{
	char	*old_value;
	char	*new_value;
	size_t	word_count;
	char	*check_point;

	if (word == NULL)
		return;
	old_value = string->value;
	word_count = lmt_unsafe_strlen(word);
	new_value = lmt_alloc(string->count + word_count + 1);
	check_point = lmt_unsafe_strcpy(new_value, string->value);
	check_point = lmt_unsafe_strcpy(check_point, word);
	*check_point = '\0';
	string->value = new_value;
	free(old_value);
}

void			lmt_string_append_lmt_string(t_lmt_string *string, t_lmt_string *word)
{
	char	*old_value;
	char	*new_value;
	char	*check_point;

	if (word == NULL)
		return;
	old_value = string->value;
	new_value = lmt_alloc(string->count + word->count + 1);
	check_point = lmt_unsafe_strcpy(new_value, string->value);
	check_point = lmt_unsafe_strcpy(check_point, word->value);
	*check_point = '\0';
	string->value = new_value;
	free(old_value);
}
