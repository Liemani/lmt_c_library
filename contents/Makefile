# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 15:06:42 by jeonpark          #+#    #+#              #
#    Updated: 2021/10/31 19:15:45 by jeonpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= liblmt_c_library.a

SRCS				:= \
					   lmt_io/lmt_write.c \
					   lmt_iterator/lmt_iterator_method.c \
					   lmt_iterator/lmt_iterator_type.c \
					   lmt_list/lmt_list_ask.c \
					   lmt_list/lmt_list_constructor.c \
					   lmt_list/lmt_list_destructor.c \
					   lmt_list/lmt_list_method.c \
					   lmt_list/lmt_list_protocol_iterator.c \
					   lmt_list/lmt_list_static_constructor.c \
					   lmt_primitive_type/lmt_atoi.c \
					   lmt_primitive_type/lmt_atol.c \
					   lmt_primitive_type/lmt_atoui.c \
					   lmt_primitive_type/lmt_is_digit.c \
					   lmt_primitive_type/lmt_is_space.c \
					   lmt_primitive_type/lmt_itoa.c \
					   lmt_primitive_type/lmt_ltoa.c \
					   lmt_primitive_type/lmt_byte_ask.c \
					   lmt_primitive_type/lmt_byte_cpy.c \
					   lmt_primitive_type/lmt_str_first_ch.c \
					   lmt_primitive_type/lmt_str_first_str.c \
					   lmt_primitive_type/lmt_str_last_ch.c \
					   lmt_primitive_type/lmt_str_last_str.c \
					   lmt_primitive_type/lmt_strcpy.c \
					   lmt_primitive_type/lmt_strdup.c \
					   lmt_primitive_type/lmt_str_ask.c \
					   lmt_primitive_type/lmt_str_count.c \
					   lmt_string/lmt_string_method.c \
					   lmt_string/lmt_string_static_constructor.c \
					   lmt_string/lmt_string_type.c \

OBJS				:= $(SRCS:.c=.o)

CC					:= clang
CFLAG				:= -Wall -Wextra -Werror

ABSTRACT_INCLUDE	:= \
					   lmt_io \
					   lmt_iterator \
					   lmt_list \
					   lmt_primitive_type \
					   lmt_string \
					   .

INCLUDE				:= $(addprefix -I ,$(ABSTRACT_INCLUDE))

LIBRARY				:=

COMPILE				= $(CC) $(CFLAG) $(INCLUDE) $(DEBUG_OPTION)
LINK				= $(CC) $(CFLAG) $(INCLUDE) $(DEBUG_OPTION) $(LIBRARY)

RM					:= rm -f



.PHONY:				all debug setdebug clean fclean re
all:				$(NAME)

debug:				clean setdebug $(NAME)
setdebug:
					$(eval DEBUG_OPTION = -g)

clean:
					$(RM) $(OBJS)
fclean:				clean
					$(RM) $(NAME)
re:					fclean all



$(NAME):			$(OBJS)
					ar rc $@ $^

%.o:				%.c
					$(COMPILE) -o $@ -c $<
