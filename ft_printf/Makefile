# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emoman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 16:11:49 by emoman            #+#    #+#              #
#    Updated: 2025/07/04 10:48:50 by emoman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = $(shell pwd)
INCDIR = $(SRCDIR)

# Source and object files
SRC = $(SRCDIR)/ft_printf.c \
      $(SRCDIR)/aux_char.c \
      $(SRCDIR)/aux_dec.c \
	  $(SRCDIR)/aux_float.c \
      $(SRCDIR)/aux_hex.c \
      $(SRCDIR)/aux_str.c \
      $(SRCDIR)/aux_vptr.c

OBJ = $(SRC:.c=.o)

# Header
INC = $(INCDIR)/ft_printf.h

# Default target
all: libftprintf.a

# Build the static library
libftprintf.a: $(OBJ)
	ar rcs $@ $^
	@echo "libftprintf.a created successfully."

# Rule to build each .o from .c
$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INC)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Remove temporary object files
clean:
	rm -f $(OBJ)

# Remove object files and the library
fclean: clean
	rm -f libftprintf.a

# Rebuild from scratch
re: fclean all

# Mark all rules as phony
.PHONY: all clean fclean re
