# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emoman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 10:13:42 by emoman            #+#    #+#              #
#    Updated: 2025/09/04 14:29:00 by emoman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Project =====
NAME    := fractol

# ===== Paths =====
VPATH   := srcs
INCDIR  := includes
MLXDIR  := minilibx-linux
OBJDIR  := obj

# ===== Tooling =====
CC      := clang
RM      := rm -f
CFLAGS  := -Wall -Wextra -Werror -O2 -MMD -MP
CPPFLAGS:= -I$(INCDIR) -I$(MLXDIR) -Ift_printf -Ilibft

# ===== Sources / Objects =====
SRCS    := main.c \
           args.c \
           draw.c \
           hooks.c \
           threads.c \
           utils.c \
           colors.c \
		   iter.c \
		   key_hooks.c \
		   julia_inter.c

# Object files and dependencies
OBJS    := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS    := $(OBJS:.o=.d)

# ===== Libs (Linux) =====
LIBS    := -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lz -pthread -Lft_printf -lftprintf -Llibft -lft

# ===== Rules =====
.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJS) $(MLXDIR)/libmlx.a ft_printf/libftprintf.a libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(MLXDIR)/libmlx.a:
	$(MAKE) -C $(MLXDIR)

ft_printf/libftprintf.a:
	$(MAKE) -C ft_printf

# Rule to build libft
libft/libft.a:
	$(MAKE) -C libft

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(MLXDIR) clean
	$(MAKE) -C ft_printf clean
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C libft fclean

re: fclean all

# Optional: debug build with sanitizers
debug: CFLAGS += -g3 -O0 -fsanitize=address,undefined
debug: re

-include $(DEPS)
