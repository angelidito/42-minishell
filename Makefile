# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:03:08 by angmarti          #+#    #+#              #
#    Updated: 2023/06/03 01:58:21 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# *****************************   PROJECT NAME   ***************************** #
# **************************************************************************** #

NAME			=	minishell

# **************************************************************************** #
# ****************************       FILES       ***************************** #
# **************************************************************************** #

SRC				=	\
					src/main.c
OBJS				=	$(SRC:.c=.o)

SRC_B			=	\
					src/main.c
OBJS_B			=	$(SRC_B:.c=.o)

# **************************************************************************** #
# *****************************       LIBS       ***************************** #
# **************************************************************************** #

INCS_DIR		=	incs
LIBS_DIR		=	libs

LIBFT_DIR		=	$(LIBS_DIR)/mylibft
LIBFT_INCS_DIR	=	$(LIBFT_DIR)/$(INCS_DIR)
LIBFT			=	$(LIBFT_DIR)/libft.a

LIBS			=	${LIBFT} 

# **************************************************************************** #
# *****************************      CONFIG      ***************************** #
# **************************************************************************** #

CC				=	@gcc
C_FLAGS			=	-Wall -Wextra -Werror #-g3 -fsanitize=address
C_INCLUDES		=	-I$(INCS_DIR) -I$(LIBFT_INCS_DIR)

LINKS			=	-lreadline

MAKES			=	make -C $(LIBFT_DIR)/
MAKES_CLEAN		=	make clean -C $(LIBFT_DIR)/
MAKES_FCLEAN	=	make fclean -C $(LIBFT_DIR)/

RM = @rm -f

# **************************************************************************** #
# *****************************      COLORS      ***************************** #
# **************************************************************************** #

GREEN			=	\033[1;32m
RED				=	\033[1;31m
BLUE			=	\033[1;34m
BBLUE			=	\033[7;49;34m
YELLOW			=	\033[1;33m
GRAY			=	\033[1;30m
NOCOLOR			=	\033[0m

# **************************************************************************** #
# *****************************       STUFF      ***************************** #
# **************************************************************************** #

%.o: %.c
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [Compilation:$(YELLOW) $@$(NOCOLOR)]$(GRAY)"
	$(CC) $(C_FLAGS) $(C_INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@${MAKES}
	@echo
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [Compilation:$(YELLOW) $@$(NOCOLOR)]$(GRAY)"
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME) ${LINKS}
	@echo
	@echo
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)-------$(BBLUE) PIPEX - OK $(NOCOLOR)$(GREEN)-------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo
	@echo

all: $(NAME)

re: fclean all

clean:
	@echo
	@${MAKES_CLEAN}
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)*.o$(NOCOLOR)]"
	$(RM) $(OBJS) $(OBJS_B)
	@echo

fclean:
	@echo
	@${MAKES_FCLEAN}
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)*.o$(NOCOLOR)]"
	$(RM) $(OBJS) $(OBJS_B)
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)$(NAME)$(NOCOLOR)]$(RED)"
	$(RM) $(NAME)
	@echo

bonus: $(OBJS_B)
	@${MAKES}
	@echo
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [Compilation:$(YELLOW) $(NAME) $@$(NOCOLOR)]$(GRAY)"
	$(CC) $(C_FLAGS) $(OBJS_B) $(LIBFT) -o $(NAME)
	@echo
	@echo
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)-------$(BBLUE) PIPEX - OK $(NOCOLOR)$(GREEN)-------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo
	@echo

.PHONY:  all bonus clean fclean re
