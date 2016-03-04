CC = gcc -Werror -Wextra -Wall -Ofast

SRCPATH = ./srcs
BRESPATH = $(SRCPATH)/bresenham
FILLPATH = $(SRCPATH)/fill

INCPATH = ./includes

LIBFT = ./libft
MINILIBX = ./minilibx_macos

HEADER = -I $(LIBFT)/includes -I $(INCPATH) -I $(MINILIBX)

LIB = $(LIBFT)/libft.a $(MINILIBX)/libmlx.a -framework OpenGL -framework AppKit 

SRC = 	$(SRCPATH)/main.c\
		$(BRESPATH)/ft_middle_point.c\
		$(SRCPATH)/ft_event.c\
		$(SRCPATH)/ft_print_form.c\
		$(SRCPATH)/ft_util.c\
		$(FILLPATH)/ft_fill.c\
		$(FILLPATH)/ft_util_fill.c\
		$(FILLPATH)/ft_debug_fill.c\

OBJ = $(SRC:.c=.o)

NAME = 3d

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@make -C $(MINILIBX)
	@$(CC) $(HEADER) $(LIB) -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(HEADER) -o $@ -c $<
	@echo "\033[33m█\033[0m\c"

clean : 
	@make -C $(LIBFT) clean
	@make -C $(MINILIBX) clean
	rm -rf $(OBJ)

fclean : clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
