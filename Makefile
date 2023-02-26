# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 19:27:43 by crigonza          #+#    #+#              #
#    Updated: 2023/02/26 22:30:08 by crigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# //= Variables =//

NAME	= fdf
BONUS	= fdf_bonus
CFLAGS	= -Werror -Wextra -Wall -w -Wunreachable-code -Ofast
LIBMLX	= ./MLX42
LIBFT	= ./Libft
GNL		= ./GNL

HEADERS	= -I ./inc -I $(LIBMLX)/include -I $(LIBFT)/include -I$(GNL)
LIBS	= -lglfw -L /usr/local/Cellar/glfw/3.3.8 $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
SRCS	= $(shell find ./src -iname "*.c") $(shell find ./GNL -iname "*.c")
BONUS_SRCS	= $(shell find ./bonus -iname "*.c") $(shell find ./GNL -iname "*.c")
OBJS	= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

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

bonus: libft libmlx $(BONUS)

libft:
	@$(MAKE) -C $(LIBFT)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(BONUS): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft