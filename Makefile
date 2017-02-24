CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = libftprintf/ft_putchar.c libftprintf/ft_strlen.c libftprintf/ft_putstr.c \
	libftprintf/ft_strcmp.c libftprintf/ft_strcpy.c libftprintf/ft_strncpy.c \
	libftprintf/ft_strdup.c libftprintf/ft_toupper.c libftprintf/ft_min.c \
	libftprintf/ft_atoi.c libftprintf/ft_strnew.c libftprintf/ft_strcat.c \
	libftprintf/is_type.c libftprintf/ft_utoa_base.c libftprintf/parse_flags.c \
	libftprintf/ft_lltoa.c libftprintf/print_argument.c libftprintf/print_argument_p.c \
	libftprintf/print_argument_xxou.c libftprintf/print_argument_c.c \
	libftprintf/print_argument_s.c libftprintf/print_argument_di.c \
	libftprintf/print_argument_cs.c libftprintf/parser_helper_funs.c \
	libftprintf/ft_strjoin.c libftprintf/string_padding.c libftprintf/ft_strchr.c\
	libftprintf/format_unsigned.c libftprintf/preparser.c libftprintf/ft_printf.c \
	libftprintf/widechar_funs.c libftprintf/copy_widestring.c

OBJ = ft_putchar.o ft_strlen.o ft_putstr.o ft_strcat.o \
	ft_strcmp.o ft_strcpy.o ft_strncpy.o ft_strdup.o \
	ft_toupper.o ft_min.o ft_atoi.o ft_strnew.o preparser.o \
	is_type.o ft_utoa_base.o parse_flags.o ft_lltoa.o \
	print_argument.o print_argument_p.o print_argument_xxou.o \
	print_argument_c.o print_argument_s.o print_argument_di.o \
	print_argument_cs.o parser_helper_funs.o ft_strchr.o \
	ft_strjoin.o string_padding.o format_unsigned.o ft_printf.o \
	widechar_funs.o copy_widestring.o


.PHONY: all comp clean fclean re

all: $(NAME)

$(OBJ): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS)

$(NAME): $(OBJ)
	@ar -rcs $@ $(OBJ)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
