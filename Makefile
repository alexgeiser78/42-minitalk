# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 13:21:50 by ageiser           #+#    #+#              #
#    Updated: 2023/05/09 15:01:54 by ageiser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[1;32m
YELLOW=\033[1;33m
RED=\033[1;31m
NO_COLOR=\033[0m

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

OBJ_DIR = obj/

SERVER = server
CLIENT = client

SRCSERVER = server.c
SRCCLIENT = client.c

SERVERBONUS = server_bonus
CLIENTBONUS = client_bonus

SRCSERVERBONUS = server_bonus.c
SRCCLIENTBONUS = client_bonus.c

OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)

OBJSERVERBONUS = $(SRCSERVERBONUS:.c=.o)
OBJCLIENTBONUS = $(SRCCLIENTBONUS:.c=.o)

DEP = $(addprefix $(OBJ_DIR), $(SRCSERVER:.c=.d), $(SRCCLIENT:.c=.d), $(SRCSERVERBONUS:.c=.d), $(SRCCLIENTBONUS:.c=.d))

TMP_OBJ = $(addprefix $(OBJ_DIR), $(OBJSERVER) $(OBJCLIENT) $(OBJSERVERBONUS) $(OBJCLIENTBONUS))

INCLUDE =  -I ./libft/ -I ./printf

LIB_DIR= ./libft
LIB = libft/libft.a
PRINT_DIR = ./printf
LIB2 = printf/libftprintf.a
RM = rm -rf

all: makelib makeprint $(OBJ_DIR) $(SERVER) $(CLIENT)                         # $(SERVERBONUS) $(CLIENTBONUS)

makelib:
	make -C $(LIB_DIR)

makeprint:
	make -C $(PRINT_DIR)

$(OBJ_DIR)%.o	:%.c Makefile
		$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
		@echo "$(GREEN) file compiled $(NO_COLOR)"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(SERVER): $(TMP_OBJ) $(LIB) $(LIB2)
		$(CC) $(CFLAGS) ./obj/server.o $(LIB) $(LIB2) -o $(SERVER)
		@echo "$(GREEN) librairy compiled and server executable generated$(NO_COLOR)"

$(CLIENT): $(TMP_OBJ) $(LIB) $(LIB2)
		$(CC) $(CFLAGS) ./obj/client.o $(LIB) $(LIB2) -o $(CLIENT)
		@echo "$(GREEN) librairy compiled and client executable generated$(NO_COLOR)"

bonus: $(TMP_OBJ) $(LIB)
		$(CC) $(CFLAGS) ./obj/server_bonus.o $(LIB) $(LIB2) -o $(SERVERBONUS)
		$(CC) $(CFLAGS) ./obj/client_bonus.o $(LIB) $(LIB2) -o $(CLIENTBONUS)	
		@echo "$(GREEN) librairy compiled and bonus executable generated$(NO_COLOR)"



clean :
		$(RM) $(OBJ_DIR)
		$(MAKE) clean -C $(LIB_DIR)
		$(MAKE) clean -C $(PRINT_DIR)
		@echo "$(RED)objects (*.o) removed$(NO_COLOR)"

fclean : clean
		$(RM) $(LIB) $(LIB2)
		$(RM) $(SERVER)
		$(RM) $(CLIENT)
		$(RM) $(SERVERBONUS)
		$(RM) $(CLIENTBONUS)
		@echo "$(RED)library (*.a) and executable removed $(NO_COLOR)"

re : fclean all
	@echo "$(YELLOW)make fclean  make all $(NO_COLOR)"

-include $(DEP)
.PHONY : all clean fclean re bonus makelib makeprint
