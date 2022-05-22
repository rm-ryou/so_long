NAME := libftprintf.a
INCDIR = -I./
LIBFTDIR = ../libft/
CFLAGS := -Wall -Wextra -Werror
SRCS = ft_printf.c\
	   ft_printf_deca.c\
	   ft_printf_hexa.c\
	   ft_printf_ptr.c\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make bonus -C $(LIBFTDIR)
	cp $(LIBFTDIR)libft.a ./
	mv libft.a $(NAME)
	ar rc $@ $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)
	make clean -C $(LIBFTDIR)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIBFTDIR)libft.a

re : fclean all

.PHONY : all clean fclean re
