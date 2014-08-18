#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouliba <kcouliba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/08/11 15:47:45 by kcouliba          #+#    #+#              #
#    Updated: 2014/08/18 23:16:16 by kcouliba         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=bsq
SRCDIR=./srcs/
INCDIR=./includes/
BINDIR=./binaries/
CC=gcc
CFLAGS=-Wall -Wextra -Werror
LINK=-I$(INCDIR)
_BIN=main.o\
 ft_strlen.o ft_strappend.o ft_strsplit.o\
 ft_print.o ft_putstr_fd.o\
 ft_atoi.o ft_pow.o\
 ft_check_grid.o
BIN= $(patsubst %, $(BINDIR)%, $(_BIN))

all:			$(BINDIR) $(NAME)

$(NAME):		$(BIN)
	@ $(CC) $(CFLAGS) -o $@ $^ $(LINK)

$(BINDIR)%.o:	$(SRCDIR)%.c
	@ $(CC) $(CFLAGS) -o $@ -c $< $(LINK)

$(BINDIR):
	@ mkdir $@

clean:
	@ rm -f $(BIN)

fclean:			clean
	@ rm -f $(NAME)
	@ rmdir $(BINDIR)

re:				fclean all

.PHONY:			all clean re fclean
