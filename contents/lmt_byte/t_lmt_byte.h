/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_byte.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:59:47 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/09 15:32:29 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_BYTE_H
# define T_LMT_BYTE_H

# include <stddef.h>	// size_t

typedef unsigned char	t_lmt_byte;

int	lmt_byte_cmp(const t_lmt_byte *lhs, const t_lmt_byte *rhs, const size_t count);

#endif
