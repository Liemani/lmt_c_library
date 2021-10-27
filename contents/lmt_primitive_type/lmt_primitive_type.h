/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_primitive_type.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:36:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 21:31:03 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_PRIMITIVE_TYPE_H
# define LMT_PRIMITIVE_TYPE_H

# include <stddef.h>	// size_t

int		lmt_is_space(const char ch);
int		lmt_is_digit(const char ch);

int		lmt_atoi(char *str, int *p_result);
int		lmt_atol(char *str, long *p_result);
int		lmt_atoui(char *str, unsigned int *p_result);
char	*lmt_itoa(int number);
char	*lmt_ltoa(long number);

///	- str
int		lmt_str_equals(const char *lhs, const char *rhs);
int		lmt_str_has_prefix(const char *str, const char *word);

size_t	lmt_str_count(const char *str);
char	*lmt_str_first_ch(char *str, char ch);
char	*lmt_str_first_str(char *str, const char *word);
char	*lmt_str_last_ch(char *str, char ch);
char	*lmt_str_last_str(char *str, const char *word);

char	*lmt_strcpy(char *target, const char *source);
char	*lmt_strdup(const char *str);

///	- byte
typedef unsigned char	t_lmt_byte;

int		lmt_byte_equals(const void *lhs, const void *rhs, size_t count);

void	*lmt_byte_cpy(void *target, const void *source, size_t size);

#endif
