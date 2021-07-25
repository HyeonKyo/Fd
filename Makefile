
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit

SRCS_DIR = ./src
SRCS_NAME = fdf.c ft_utils.c get_next_line.c get_next_line_utils.c parse1.c \
			parse2.c parse_utils.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))

OBJS_DIR = ./obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_NAME:.c=.o))

INC_DIR = ./include

LIBS = libft.a libmlx.a

NAME = fdf

RM = rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $@ $(MLX_FLAGS) $^ $(LIBS)

$(OBJS_DIR)/%.o	:	$(SRCS_DIR)/%.c
					mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $^

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
