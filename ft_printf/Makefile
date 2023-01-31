NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printchar.c \
		ft_printf.c \
		ft_printhex.c \
		ft_printhex2.c \
		ft_printnbr.c \
		ft_printnbr_base.c \
		ft_printstr.c \
		ft_printunsigned.c \
		ft_printptr.c

OBJ = $(SRC:c=o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -crs $(NAME) $(OBJ)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re