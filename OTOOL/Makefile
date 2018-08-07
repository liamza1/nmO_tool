# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstreak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/03 11:06:50 by lstreak           #+#    #+#              #
#    Updated: 2018/08/03 11:07:11 by lstreak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_otool
CCLIB = -Llibft -lft
CCFLAGS = -Wall -Werror -Wextra
SRCDIR = src
OBJDIR = obj
INCDIR = includes libft libft/printf/includes

SRC =	main.c\
		utils.c\
		header.c\
		sections.c\
		fat.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
	@make -C libft
	@gcc $(CCLIB) -o $(NAME) $(OBJS) libft/printf/libftprintf.a

build:
	@mkdir -p $(OBJDIR)

clean:
	@make -C libft clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

dev : all
	@./$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc -c $(CCFLAGS) $(INCS) -o $@ $<
