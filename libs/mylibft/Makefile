# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:17:59 by angmarti          #+#    #+#              #
#    Updated: 2023/06/05 11:21:28 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	\
			src/ft_atoi.c \
			src/ft_bzero.c \
			src/ft_calloc.c \
			src/ft_isalnum.c \
			src/ft_isalpha.c \
			src/ft_isascii.c \
			src/ft_isdigit.c \
			src/ft_isprint.c \
			src/ft_isspace.c \
			src/ft_itoa.c \
			src/ft_lstadd_back_bonus.c \
			src/ft_lstadd_front_bonus.c \
			src/ft_lstclear_bonus.c \
			src/ft_lstdelone_bonus.c \
			src/ft_lstiter_bonus.c \
			src/ft_lstlast_bonus.c \
			src/ft_lstmap_bonus.c \
			src/ft_lstnew_bonus.c \
			src/ft_lstsize_bonus.c \
			src/ft_memchr.c \
			src/ft_memcmp.c \
			src/ft_memcpy.c \
			src/ft_memmove.c \
			src/ft_memset.c \
			src/ft_printf.c \
			src/ft_printf_puts_bases_fd.c \
			src/ft_printf_puts_fd.c \
			src/ft_putchar_fd.c \
			src/ft_putendl_fd.c \
			src/ft_putnbr_fd.c \
			src/ft_putstr_fd.c \
			src/ft_split.c \
			src/ft_split_not_escaped.c \
			src/ft_str_replace_dup_whitespaces.c \
			src/ft_strarr.c \
			src/ft_strchr.c \
			src/ft_strcmp.c \
			src/ft_strdup.c \
			src/ft_striteri.c \
			src/ft_strjoin.c \
			src/ft_strlcat.c \
			src/ft_strlcpy.c \
			src/ft_strlen.c \
			src/ft_strmapi.c \
			src/ft_strncmp.c \
			src/ft_strnstr.c \
			src/ft_strrchr.c \
			src/ft_strtrim.c \
			src/ft_substr.c \
			src/ft_tolower.c \
			src/ft_toupper.c \
			src/get_next_line.c \
			src/get_next_line_utils.c



OBJS	= $(SRCS:.c=.o)

#----------------------------------------------------------COMPILER
NAME	= libft.a
CC 		= @gcc
CFLAGS	= -Wall -Werror -Wextra


#----------------------------------------------------------RULES
%.o: %.c
#	@echo "\033[32mLibft:\033[0m [Compilation:\033[33m $< $@\033[0m]\033[30m"
	-@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	@echo "\033[32mLibft:\033[0m [Compilation:\033[33m *.o *.c\033[0m]\033[30m"
# ${CC} ${CFLAGS} -c ${SRCS}
	@echo "\033[32mLibft:\033[0m [Compilation:\033[33m $@\033[0m]\033[30m"
	@ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	@echo "\033[32mLibft:\033[0m [\033[31mRemoving \033[34m*.o\033[0m]\033[31m"
	@rm -f ${OBJS}

fclean: clean
	@echo "\033[32mLibft:\033[0m [\033[31mRemoving \033[34m$(NAME)\033[0m]\033[31m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
