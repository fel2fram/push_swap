# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 14:09:57 by fde-fram          #+#    #+#              #
#    Updated: 2019/11/09 14:21:13 by simoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = ./

CC = gcc

WALL = -Wall -Wextra -Werror

SRC = ft_isalnum.c ft_isprint.c ft_tolower.c ft_isalpha.c ft_strlen.c ft_toupper.c ft_atoi.c ft_isascii.c ft_memchr.c ft_memset.c ft_isdigit.c ft_putchar_fd.c ft_split.c ft_strlcat.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

OBJB = $(BONUS:.c=.o)

all	: $(NAME)

%.o: %.c
	$(CC) -I $(HEADERS) -c $(WALL) $< -o $@ 

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus : $(OBJ) $(OBJB)
	ar -rc $(NAME) $(OBJ) $(OBJB)
	ranlib $(NAME)

clean :
	rm -f $(OBJ) $(OBJB)

fclean : clean
	rm -f $(NAME)

re : fclean all

