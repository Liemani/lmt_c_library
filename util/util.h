/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/15 23:21:21 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdlib.h>
# include <sys/types.h>
# include "t_read_info.h"
# include "lmt_exit.h"
# include "bool.h"

# define PARSE_SUCCESSFUL	0
# define PARSE_FAIL			1

void	*lmt_alloc(size_t size);
ssize_t	lmt_read(int fd, void *buffer, size_t size);
void	lmt_put_ch(const char ch);
ssize_t	lmt_write(const char *string);
char	*lmt_realloc_string(char *string, size_t size);
int		lmt_atoui(char *string, unsigned int *p_result);
int		lmt_atoi(char *string, int *p_result);
char	*lmt_itoa(int n);
int		lmt_is_space(const char ch);
int		lmt_is_digit(const char ch);

#endif
