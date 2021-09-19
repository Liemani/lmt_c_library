#ifndef T_LMT_STRING_H
# define T_LMT_STRING_H

# include <stddef.h>

typedef struct s_lmt_string
{
	char	*value;
	size_t	count;
}	t_lmt_string;

void			lmt_string_init(t_lmt_string *string, const char *value);
t_lmt_string	*lmt_string_new(const char *value);
void			lmt_string_free(t_lmt_string *p_lmt_string);

t_lmt_string	*lmt_string_split(t_lmt_string *string, char *separator);
void			lmt_string_append_string(t_lmt_string *string, char *word);
void			lmt_string_append_lmt_string(t_lmt_string *string, t_lmt_string *word);

#endif
