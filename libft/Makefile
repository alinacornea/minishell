# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcornea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 14:16:03 by alcornea          #+#    #+#              #
#    Updated: 2017/06/19 19:49:50 by alcornea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC= gcc
CFLAGS+= -Wall -Wextra -Werror

LIB_PATH= ./libft/
PF_PATH= ./ft_printf/

LIBFT_SRC+= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
						ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c \
						ft_memdel.c \
						ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
						ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
						ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
						ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
						ft_toupper.c ft_tolower.c \
						ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
						ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
						ft_strtrim.c ft_strsplit.c \
						ft_itoa.c ft_ftoa.c \
						ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
						ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
						ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
						ft_realloc.c ft_get_word_len.c ft_strrev.c ft_is_prim.c ft_countwords.c \
						ft_strupcase.c ft_strlowcase.c ft_strndup.c \
					 	get_next_line.c \
						ft_wstrdup.c ft_wstrsub.c ft_wmemset.c ft_wstrjoin.c ft_wcharsize.c \
						ft_itoa_base.c ft_putwchar.c

PRINTF_SRC= ft_printf.c \
						get_modifiers.c \
						invalid_conversion.c \
						ft_itoa_x_base.c \
						initialize.c \
						check_flags.c \
						convert_int_to_ascii.c \
						convert_unsigned_to_ascii.c \
						convert_long_long_to_ascii.c \
						handle_integers.c \
						convert_integers.c \
						handle_big_d.c \
						handle_big_u.c \
						handle_flags.c \
						handle_plus_space.c \
						handle_unsigned_int.c \
						handle_pointers.c \
						handle_hex.c \
						handle_octal.c \
						handle_chars.c \
						handle_uns_chars.c \
						handle_strings.c \
						handle_wchar_t.c \
						handle_wstr_t.c \
						handle_float.c \
						my_strlen.c


SRC = $(addprefix $(LIB_PATH),$(LIBFT_SRC))

OBJ_PATH = ./obj/

OBJ_SRC = $(LIBFT_SRC:.c=.o)\
		$(PRINTF_SRC:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_SRC))

INC_PATH = ./includes/
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(OBJ_PATH)%.o: $(LIB_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(PF_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@ar -rc $(NAME) $?
	@ranlib $(NAME)

clean:
		@rm -rf $(OBJ_PATH)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
