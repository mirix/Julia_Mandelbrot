# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emoman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 16:11:49 by emoman            #+#    #+#              #
#    Updated: 2025/06/24 16:25:19 by emoman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = $(shell pwd)
INCDIR = $(SRCDIR)

# Mandatory source files
MANDATORY_SRC = $(SRCDIR)/ft_isalpha.c \
      $(SRCDIR)/ft_isdigit.c \
      $(SRCDIR)/ft_isalnum.c \
      $(SRCDIR)/ft_isascii.c \
      $(SRCDIR)/ft_isprint.c \
      $(SRCDIR)/ft_memset.c \
      $(SRCDIR)/ft_strlen.c \
      $(SRCDIR)/ft_bzero.c \
      $(SRCDIR)/ft_memcpy.c \
      $(SRCDIR)/ft_memmove.c \
      $(SRCDIR)/ft_strlcpy.c \
      $(SRCDIR)/ft_strlcat.c \
      $(SRCDIR)/ft_toupper.c \
      $(SRCDIR)/ft_tolower.c \
      $(SRCDIR)/ft_strchr.c \
      $(SRCDIR)/ft_strrchr.c \
      $(SRCDIR)/ft_strncmp.c \
      $(SRCDIR)/ft_memchr.c \
      $(SRCDIR)/ft_memcmp.c \
      $(SRCDIR)/ft_strnstr.c \
      $(SRCDIR)/ft_atoi.c \
      $(SRCDIR)/ft_calloc.c \
      $(SRCDIR)/ft_strdup.c \
      $(SRCDIR)/ft_substr.c \
      $(SRCDIR)/ft_strjoin.c \
      $(SRCDIR)/ft_strtrim.c \
      $(SRCDIR)/ft_split.c \
      $(SRCDIR)/ft_itoa.c \
      $(SRCDIR)/ft_strmapi.c \
      $(SRCDIR)/ft_striteri.c \
      $(SRCDIR)/ft_putchar_fd.c \
      $(SRCDIR)/ft_putstr_fd.c \
      $(SRCDIR)/ft_putendl_fd.c \
      $(SRCDIR)/ft_putnbr_fd.c

# Bonus source files
BONUS_SRC = $(SRCDIR)/ft_lstnew.c \
	    $(SRCDIR)/ft_lstadd_front.c \
	    $(SRCDIR)/ft_lstsize.c \
	    $(SRCDIR)/ft_lstlast.c \
	    $(SRCDIR)/ft_lstadd_back.c \
	    $(SRCDIR)/ft_lstdelone.c \
	    $(SRCDIR)/ft_lstclear.c \
	    $(SRCDIR)/ft_lstiter.c \
	    $(SRCDIR)/ft_lstmap.c

# Object files
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Logic to include sources on the basis of target
ifeq ($(MAKECMDGOALS),bonus)
	OBJ = $(MANDATORY_OBJ) $(BONUS_OBJ)
else ifeq ($(MAKECMDGOALS),all)
	OBJ = $(MANDATORY_OBJ) $(BONUS_OBJ)
else
	OBJ = $(MANDATORY_OBJ)
endif

# Header
INC = $(INCDIR)/libft.h

# Default target
default: mandatory

#Build targets
mandatory: libft.a
all: libft.a
bonus: libft.a

# Build the static library
libft.a: $(OBJ)
	ar rcs $@ $^
	@echo "libft.a created successfully."

# Rule to build each .o from .c
$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INC)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Remove itemporary object files
clean:
	rm -f $(MANDATORY_OBJ) $(BONUS_OBJ)

# Remove object files and the library
fclean: clean
	rm -f libft.a

# Rebuild from scratch
re: fclean all

# Mark all rules as phony
.PHONY: default mandatory all bonus clean fclean re
