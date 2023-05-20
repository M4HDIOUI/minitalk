# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omahdiou <omahdiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 17:34:24 by omahdiou          #+#    #+#              #
#    Updated: 2023/04/10 01:37:46 by omahdiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME = client
CBONUS = client_bonus

SNAME = server
SBONUS = server_bonus

CC = cc

FLAG = -Wall -Wextra -Werror

HDR = minitalk.h

SRC = utils.c client.c server.c
SRCB = utils.c client_bonus.c server_bonus.c

red= \e[0;31m
green= \e[0;32m

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(SNAME) $(CNAME)
bonus: $(CBONUS) $(SBONUS)

$(CNAME): utils.o client.o
	@$(CC) $(FLAG) $^ -o $(CNAME)

$(SNAME): utils.o server.o
	@$(CC) $(FLAG) $^ -o $(SNAME)
	@printf "$(green)done \n"

$(CBONUS): utils.o client_bonus.o
	@$(CC) $(FLAG) $^ -o $(CBONUS)

$(SBONUS): utils.o server_bonus.o
	@$(CC) $(FLAG) $^ -o $(SBONUS)
	@printf "$(green)done \n"

%.o : %.c $(HDR)
	@$(CC) $(FLAG) -c $< -o $@
	

clean :
	@rm -rf $(OBJ) $(OBJB)
	@rm -rf $(CNAME) $(SNAME)
	@printf "$(red)done \n"

fclean : clean
	@rm -rf $(SBONUS) $(CBONUS)

re: fclean all bonus
