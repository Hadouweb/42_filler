CC = gcc -Werror -Wextra -Wall

SRCPATH = ./srcs

INCPATH = ./includes

LIBFT = ../libft

HEADER = -I $(LIBFT)/includes -I $(INCPATH)

LIB = -L$(LIBFT) -lft -lncurses

SRC = 	$(SRCPATH)/main.c\

OBJ = $(SRC:.c=.o)

NAME = visu

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(HEADER) $(LIB) -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(HEADER) -o $@ -c $<
	@echo "\033[33m█\033[0m\c"

clean : 
	@make -C $(LIBFT) clean
	rm -rf $(OBJ)

fclean : clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re