#ifndef T_LMT_STRING_H
# define T_LMT_STRING_H

typedef struct s_lmt_string
{
	char	*value;
	int		count;
}	t_lmt_string;

void			lmt_string_init(t_lmt_string *string, const char *value);
t_lmt_string	*lmt_string_new(const char *value);
void			lmt_string_free(t_lmt_string *p_lmt_string);

t_lmt_string	*lmt_string_split(t_lmt_string *string, char *separator);

#endif
