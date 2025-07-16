CFLAGS	=	-Wall -Werror -Wextra
AR		=	ar rcs
CC		=	cc
RM		=	rm -rf
NAME	=	libftprintf.a

SRC 	=	ft_printf.c \
			ft_print_char.c \
			ft_print_str.c \
			ft_print_int.c \
			ft_print_uint.c \
			ft_print_hex.c
OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) test
	$(RM) ft_printf_main.c

re: fclean all

TEST_PRINT=\\e[1;34m******* TESTING $< ********\\e[0m
TEST_OKEND=\\e[1;34m******* ALL OK $< *********\\e[0m

ft_printf_main.c:
	wget -O $@ https://github.com/Laiagdla/testmain/raw/refs/heads/main/ft_printf_main.c;

test: ft_printf_main.c re $(OBJ)
	$(CC) $(CFLAGS) $< -o test -L. -lftprintf
	@echo "${TEST_PRINT}"
	./test
	@echo "${TEST_OKEND}"


.PHONY: all clean fclean re test
