#ifndef T_LMT_STRING_H
# define T_LMT_STRING_H

typedef struct s_lmt_string
{
	char	*value;
	int		count;
}	t_lmt_string;

t_lmt_string	*lmt_string_new(void);
void	lmt_string_free(t_lmt_string *p_lmt_string);

#endif
