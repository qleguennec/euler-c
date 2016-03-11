# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/25 17:44:49 by qle-guen          #+#    #+#              #
#    Updated: 2016/03/11 22:39:47 by qle-guen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
BINDIR		=	.
SRCDIR		=	src
BUILDDIR	=	build
LIBDIR		=	lib
INCLUDE		=	include
NAME		=	euler
PBDIR		=	$(SRCDIR)/problems
TARGET		=	$(BINDIR)/$(NAME)

# Check if PB is set, if not set it to last problem
ifndef PB
PB			=	$(shell ls $(PBDIR) | tail -n1 | cut -d. -f1 | sed 's/problem//')
endif

# Compiler options
CC			=	gcc
LIBFLAGS	=	-L$(BUILDDIR) $(subst lib,-l,$(LIBSRC)) -lm
CFLAGS		=	-I$(INCLUDE) -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -g

# Color output
BLACK		=	"\033[0;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[0;34m"
MAGENTA		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[0;37m"
END			=	"\033[0m"

# Source files
SRC			+=	main.c
SRC			+=	common.c
SRC			+=	intlist.c
SRC			+=	factors.c

# Libraries
LIBSRC		+=

OBJECTS		=	$(addprefix $(BUILDDIR)/, $(SRC:%.c=%.o))
LIBS		=	$(addprefix $(BUILDDIR)/, $(addsuffix .a,$(LIBSRC)))

all: $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(BUILDDIR)
	@$(CC) $(CFLAGS) -c $(PBDIR)/problem$(PB).c -o $(BUILDDIR)/problem.o
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN)+++ obj: $(YELLOW)$(@F)$(END)

$(BUILDDIR)/%.a: $(LIBDIR)/% $(BUILDDIR)
	@make -s -C $<
	@cp $</$(@F) $@
	@echo $(GREEN)+++ lib: $(CYAN)$(@F)$(END)

$(TARGET): $(LIBS) $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(BUILDDIR)/problem.o $(LIBFLAGS)
	@echo $(GREEN)+++ bin: $(BLUE)$(NAME)$(END)

$(BUILDDIR):
	@mkdir build/

.PHONY: clean
clean:
	@rm -f $(LIBS)
	@echo $(RED)--- lib: $(CYAN)$(LIBS:$(BUILDDIR)/%=%)$(END)
	@rm -f $(OBJECTS)
	@echo $(RED)--- obj: $(YELLOW)$(OBJECTS:$(BUILDDIR)/%=%) $(BUILDDIR)/problem.o$(END)
	@rm -rf build/

.PHONY:	fclean
fclean: clean
	@rm -f $(TARGET)
	@echo $(RED)--- bin: $(BLUE)$(NAME)$(END)

.PHONY: re
re: fclean all

.PHONY: test
test: all
	@./euler test

.PHONY: solve
solve: all
	@./euler solve
