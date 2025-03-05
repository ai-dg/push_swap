SRC =	init_data.c instructions_1.c instructions_2.c \
		main.c malloc_tools.c nodes_and_tools.c \
		nodes.c parsing_1.c parsing_2.c \
		parsing_3.c sort_stack_1.c sort_stack_2.c \
		sort_stack_3.c sort_stack_4.c sort_stack_5.c \
		sort_stack_6.c sort_stack_7.c sort_stack_8.c \
		sort_stack_9.c sort_stack_10.c sort_stack_11.c \
		sort_stack_12.c sort_stack_13.c tools_1.c \
		tools_2.c tools_3.c

OBJ =	$(SRC:.c=.o)
NAME = push_swap

CC	= cc	
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I.

all : $(NAME)

$(NAME) : $(OBJ) 
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)


re : fclean all

.PHONY : all clean fclean re
