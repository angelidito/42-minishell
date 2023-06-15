# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:03:08 by angmarti          #+#    #+#              #
#    Updated: 2023/06/14 23:37:34 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# *****************************   PROJECT NAME   ***************************** #
# **************************************************************************** #

NAME			=	minishell
NAME_PIPEX		=	pipex

# **************************************************************************** #
# ****************************       FILES       ***************************** #
# **************************************************************************** #

# ****************************     MINISHELL     ***************************** #
SRC				=	\
					src/pipex/case_n_cmds.c \
					src/pipex/checking_setting.c \
					src/pipex/errors.c \
					src/pipex/get_cmd_args.c \
					src/pipex/getting_executing.c \
					src/pipex/here_doc.c \
					src/pipex/pipex.c \
					src/cmd.c \
					src/env.c \
					src/utils.c \
					src/main.c
					
# src/pipex/ft_functions.c

OBJS				=	$(SRC:.c=.o)

# ****************************       PIPEX       ***************************** #
SRC_PIPEX		=	\
					src/pipex/case_n_cmds.c \
					src/pipex/checking_setting.c \
					src/pipex/errors.c \
					src/pipex/get_cmd_args.c \
					src/pipex/getting_executing.c \
					src/pipex/here_doc.c \
					src/pipex/pipex.c \
					src/env.c \
					src/utils.c \
					src/pipex/pipex_main.c
					
OLD_SRC_PIPEX	=	\
					src/pipex/backslashes.c \
					src/pipex/case_n_cmds.c \
					src/pipex/checking_setting.c \
					src/pipex/errors.c \
					src/pipex/get_cmd_args.c \
					src/pipex/getting_executing.c \
					src/pipex/here_doc.c \
					src/pipex/pipex_main.c
# src/pipex/ft_split_not_escaped.c \
# src/pipex/ft_functions.c 
OBJS_PIPEX		=	$(SRC_PIPEX:.c=.o)


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
	@echo "$(NOCOLOR)[$(GREEN)-----$(BBLUE) MINISHELL - OK $(NOCOLOR)$(GREEN)-----$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo
	@echo

all: $(NAME)

re: fclean all

clean:
	@echo
	@${MAKES_CLEAN}
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)*.o$(NOCOLOR)]"
	$(RM) $(OBJS) $(OBJS_PIPEX)
	@echo

fclean:
	@echo
	@${MAKES_FCLEAN}
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)*.o$(NOCOLOR)]"
	$(RM) $(OBJS) $(OBJS_PIPEX)
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)$(NAME)$(NOCOLOR)]$(RED)"
	$(RM) $(NAME) $(NAME_PIPEX)
	@echo

$(NAME_PIPEX): $(OBJS_PIPEX)
	@${MAKES}
	@echo
	@echo "$(GREEN)$(NAME_PIPEX):$(NOCOLOR) [Compilation:$(YELLOW) $@$(NOCOLOR)]$(GRAY)"
	$(CC) $(C_FLAGS) $(OBJS_PIPEX) $(LIBFT) -o $(NAME_PIPEX) ${LINKS}
	@echo
	@echo
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)-------$(BBLUE) PIPEX - OK $(NOCOLOR)$(GREEN)-------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo
	@echo

.PHONY:  all bonus clean fclean re
