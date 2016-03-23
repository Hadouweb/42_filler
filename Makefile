CC = gcc -Werror -Wextra -Wall

SRCPATH = ./srcs

INCPATH = ./includes

LIBFT = ./libft

HEADER = -I $(LIBFT)/includes -I $(INCPATH)

LIB = $(LIBFT)/libft.a

SRC = 	$(SRCPATH)/main.c\
		$(SRCPATH)/ft_init.c\
		$(SRCPATH)/ft_set_data.c\
		$(SRCPATH)/ft_util.c\
		$(SRCPATH)/ft_generate_pos.c\
		$(SRCPATH)/ft_set_point.c\
		$(SRCPATH)/ft_browse_board.c\
		$(SRCPATH)/ft_place_piece_left_right.c\
		$(SRCPATH)/ft_place_piece_top_bot.c\

OBJ = $(SRC:.c=.o)

NAME = filler

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
