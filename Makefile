# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 09:19:15 by simoulin          #+#    #+#              #
#    Updated: 2019/08/21 15:28:04 by simoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

SRCS = 	pile.c actions.c util.c check_sorted.c get_next_line.c get_next_line_utils.c checker_util.c 

SRCS1 = push_swap_util2.c push_swap_util.c push_swap.c

SRCS2 = checker.c

OBJSRCS = $(SRCS:.c=.o) 
OBJSRCS1 = $(SRCS1:.c=.o)
OBJSRCS2 = $(SRCS2:.c=.o)

all : $(NAME1) $(NAME2)

$(NAME1) : $(OBJSRCS) $(OBJSRCS1)
	@echo "\033[33m[Remove last version...]"
	@rm -rf push_swap
	@echo "\033[33m[Libft compilation...]"
	@$(MAKE) -C ./libft
	@echo "\033[33m[push_swap compilation...]"
	@gcc $(OBJSRCS1) $(OBJSRCS) -I./libft -Wall -Wextra -Werror ./libft/libft.a -o $(NAME1)
	@echo "\033[33m[push_swap done !]"

$(NAME2) : $(OBJSRCS) $(OBJSRCS2)
	@echo "\033[33m[Remove last version...]"
	@rm -rf checker
	@echo "\033[33m[Libft compilation...]"
	@$(MAKE) -C ./libft
	@echo "\033[33m[Checker compilation...]"
	@gcc $(OBJSRCS2) $(OBJSRCS) -I./libft -Wall -Wextra -Werror ./libft/libft.a -o $(NAME2)
	@echo "\033[33m[checker done !]"

clean :
	rm -rf $(OBJSRCS) $(OBJSRCS1) $(OBJSRCS2)
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME1) $(NAME2)

re : fclean all