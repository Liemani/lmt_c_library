NAME				:= liblmt_c_library.a

SRCS				:= \
					   lmt_alloc/lmt_alloc.c \
					   lmt_byte/lmt_byte_cmp.c \
					   lmt_fcntl/lmt_close.c \
					   lmt_fcntl/lmt_open.c \
					   lmt_io/lmt_put_ch.c \
					   lmt_io/lmt_read.c \
					   lmt_io/lmt_write.c \
					   lmt_primitive_type/lmt_atoi.c \
					   lmt_primitive_type/lmt_atol.c \
					   lmt_primitive_type/lmt_atoui.c \
					   lmt_primitive_type/lmt_is_digit.c \
					   lmt_primitive_type/lmt_is_space.c \
					   lmt_primitive_type/lmt_itoa.c \
					   lmt_primitive_type/lmt_ltoa.c \
					   lmt_sequence/t_lmt_sequence_element_method.c \
					   lmt_sequence/t_lmt_sequence_element_type.c \
					   lmt_sequence/t_lmt_sequence_method.c \
					   lmt_sequence/t_lmt_sequence_type.c \
					   lmt_string/t_lmt_string_method.c \
					   lmt_string/t_lmt_string_type.c \
					   lmt_unsafe/lmt_unsafe_memcpy.c \
					   lmt_unsafe/lmt_unsafe_strchr.c \
					   lmt_unsafe/lmt_unsafe_strcpy.c \
					   lmt_unsafe/lmt_unsafe_strdup.c \
					   lmt_unsafe/lmt_unsafe_string_starts.c \
					   lmt_unsafe/lmt_unsafe_strlen.c \
					   lmt_unsafe/lmt_unsafe_strrchr.c

OBJS				:= $(SRCS:.c=.o)

CC					:= clang
CFLAG				:= -Wall -Wextra -Werror

ABSTRACT_INCLUDE	:= \
					   lmt_alloc \
					   lmt_byte \
					   lmt_fcntl \
					   lmt_io \
					   lmt_primitive_type \
					   lmt_sequence \
					   lmt_string \
					   lmt_unsafe \
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
