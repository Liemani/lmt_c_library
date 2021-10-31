/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_string_static.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:33:13 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 19:29:11 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_STRING_STATIC_H
# define LMT_STRING_STATIC_H

# include "lmt_string.h"

t_lmt_string	*lmt_string_alloc(void);
int				lmt_string_init(t_lmt_string *string, const char *str);

#endif
