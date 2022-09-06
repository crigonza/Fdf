# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 19:27:43 by W2Wizard          #+#    #+#              #
#    Updated: 2022/08/11 19:55:06 by crigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# //= Variables =//

NAME	= fdf
CFLAGS	= -w -Wunreachable-code -Ofast
LIBMLX	= ./MLX42
LIBFT	= ./Libft
GNL		= ./GNL

HEADERS	= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include -I$(GNL)
LIBS	= -lglfw -L /opt/homebrew/cellar/glfw/3.3.7/lib $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
SRCS	= $(shell find ./src -iname "*.c") $(shell find ./GNL -iname "*.c")
OBJS	= ${SRCS:.c=.o}

BOLD	= \033[1m
BLACK	= \033[30;1m
RED	= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

# //= Recipes =//

all: libft libmlx $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft