NAME	= wordle
CC		= cc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -g -MD -MP

SRCS	= main.c lib_list.c lib_table.c get_next_line.c get_next_line_utils.c \
		parser.c error_exit.c randominette.c frontend.c colors.c

OBJS_DIR	= objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DEPS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.d))

all		: $(NAME)

$(NAME)	: ${OBJS}
		$(CC) $(CFLAGS) -o $@ $^

objs/%.o	: %.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ -I .

clean	:
		$(RM) $(OBJS_DIR)

fclean	:
		$(RM) $(OBJS_DIR) $(NAME)

re		: fclean all

play	: all
		clear; ./wordle

-include $(DEPS)

.PHONY: all clean fclean re
