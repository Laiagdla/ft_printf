CFLAGS	=	-Wall -Werror -Wextra
AR		=	ar rcs
CC		=	cc
RM		=	rm -rf
NAME	=	libftprintf.a

SRC 	=	ft_printf.c ft_bzero.c ft_print_char.c ft_print_str.c
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

re: fclean all

# cleanlog:
# 	echo "" > build.log

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
# 	gcc -nostartfiles -shared -o libft.so $(OBJ)

# TEST_PRINT=\\e[1;34m******* TESTING $< ********\\e[0m
# TEST_OKEND=\\e[1;34m******* ALL OK $< *********\\e[0m

# OBJ		=	$(addprefix build/,$(SRC:.c=.o))
# OBJBONUS=	$(addprefix build/,$(SRC:.c=.o)) $(addprefix build/,$(BONUS:.c=.o))
# build:
# 	mkdir -p build

# build/%.o:	%.c build
# 	$(CC) $(CFLAGS) -c $< -o $@

test: $(OBJ)
	$(CC) $(CFLAGS) main.c -o test -L. -lftprintf


# test: bonus $(OBJBONUS)
# 	@$(CC) $(CFLAGS) libft.c -o libft -L. -lft -lbsd -I.
# 	@echo "${TEST_PRINT}"
# 	@./libft
# 	@echo "${TEST_OKEND}"

# downloadtest:
# 	@if [ ! -L libft.c ]; then \
# 	wget -O libft.c https://github.com/Laiagdla/testmain/raw/refs/heads/main/libft.c >> build.log 2>&1; \
# 	fi

.PHONY: all clean fclean re cleanlog
