# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 18:51:23 by sayar             #+#    #+#              #
#    Updated: 2022/10/09 18:59:55 by zkasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAGS = -Wall -Werror -Wextra

RD = -lreadline -L /Users/zkasmi/.brew/Cellar/readline/8.1.2/lib  -I /Users/zkasmi/.brew/Cellar/readline/8.1.2/include -g

RD_INC = -I /Users/zkasmi/.brew/Cellar/readline/8.1.2/include

SRC_mini = ./main/minishell.c

ALL_OF_SRC = main/change.c\
			 main/error.c\
			 main/errutils.c\
			 main/exec.c\
			 main/exec_utils.c\
			 main/ft_check.c\
			 main/ft_execve.c\
			 main/ft_fork.c\
			 main/collect_adr.c\
			 main/path.c\
			 main/multi_cmd.c\
			 main/init.c\
			 main/simple_cmd.c\
			 main/signal.c\
			 built_in/cd.c\
			 built_in/cd_utils.c\
			 built_in/cd_utils_2.c\
			 built_in/cd_utils_3.c\
			 built_in/export.c\
			 built_in/export_utils.c\
			 built_in/export_utils_1.c\
			 built_in/ft_env.c\
			 built_in/ft_exit.c\
			 built_in/unset.c\
			 built_in/unset_utils.c\
			 built_in/export_utils_2.c\
			 built_in/echo.c\
			 built_in/lst_env.c\
			 built_in/pwd.c\
			 built_in/set_env.c\
			 expansion/expansion.c\
			 expansion/expansion_utils.c\
			 expansion/expansion_utils_2.c\
			 parsing/parsing.c\
			 parsing/tokens.c\
			 parsing/tokens_utils.c\
			 parsing/utils.c\
			 rdr/create_rdr.c\
			 rdr/heredoc.c\
			 rdr/parsing_rdr_input.c\
			 rdr/parsing_rdr_output.c\
			 rdr/rdr_output.c\
			 rdr/redirection.c\

PREFIX = ./obj/

OBJ_mini = $(addprefix $(PREFIX), $(SRC_mini:.c=.o))

OBJ_SRC = $(addprefix $(PREFIX), $(ALL_OF_SRC:.c=.o))

OBJ_Lib = ./Libft/libft.a

OBJ_perror = ./ft_perror/libftprintf.a

all: Lib perror $(NAME)

$(PREFIX) :
	@mkdir -p $(PREFIX)
	@mkdir -p $(PREFIX)/rdr
	@mkdir -p $(PREFIX)/parsing
	@mkdir -p $(PREFIX)/main
	@mkdir -p $(PREFIX)/expansion
	@mkdir -p $(PREFIX)/built_in

$(PREFIX)%.o: %.c ./includes/minishell.h
			-${CC} $(CFLAGS) $(RD_INC) -g -c -o $@ $<

$(NAME) : $(PREFIX) $(OBJ_mini) $(OBJ_SRC) $(OBJ_Lib) $(OBJ_perror)
			-$(CC) $(CFLAGS) $(RD) $(OBJ_mini) $(OBJ_SRC) $(OBJ_Lib) $(OBJ_perror) -g -lreadline -o $(NAME)

perror:
	@$(MAKE) -C ft_perror

perrorclean:
	@$(MAKE) -C ft_perror clean

perrorfclean:
	@$(MAKE) -C ft_perror fclean

Lib:
	@$(MAKE) -C Libft

Libclean:
	@$(MAKE) -C Libft clean

Libfclean:
	@$(MAKE) -C Libft fclean

.PHONY: all clean fclean re

clean:	perrorclean Libclean
		rm -f $(OBJ_mini) $(OBJ_SRC)
		@rm -rf $(PREFIX)

fclean: clean Libfclean perrorfclean
		rm -f $(NAME)

re: fclean all
