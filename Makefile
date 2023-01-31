CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = fractol
SRC = main.c mandelbrot.c color.c window.c exit_window.c zoom.c
OBJ = $(SRC:.c=.o)


MLX_DIR = mlx_linux
MLX_BINARY = libmlx_Linux.a
FTPRINTF_BINARY = libftprintf.a
LIBFT_BINARY = libft.a
HEADER = fractol.h

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -O3 -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $^ -lmlx -lm -framework OpenGL -framework AppKit -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all