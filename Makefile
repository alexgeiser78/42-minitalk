# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 13:21:50 by ageiser           #+#    #+#              #
#    Updated: 2023/04/18 16:50:25 by ageiser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[1;32m
YELLOW=\033[1;33m
RED=\033[1;31m

SERVER = server
CLIENT = client

SRCSERVER = server.c
SRCCLIENT = client.c

SERVERBONUS = server_bonus
CLIENTBONUS = client_bonus

SRCSERVERBONUS = server_bonus.c
SRCCLIENTBONUS = client_bonus.c

OBJSERVER = ${SRCSERVER:.c=.o}
OBJCLIENT = ${SRCCLIENT:.c=.o}

OBJSERVERBONUS = ${SRCSERVERBONUS:.c=.o}
OBJCLIENTBONUS = ${SRCCLIENTBINUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj/

DEP = $(addprefix $(OBJ_DIR), $(SRC_SERVER:.c=.d))
      $(addprefix $(OBJ_DIR), $(SRC_CLIENT:.c=.d))

TMP_OBJ = $(addprefix $(OBJ_DIR), $(OBJSERVER))
	  $(addprefix $(OBJ_DIR), $(OBJCLIENT))

INCLUDE =   -I ./include/	-I ./libft/

LIB_DIR = ./libft/
LIB = ./libft/libft.a

RM = rm -rf

makelib:
	make -C $(LIB_DIR)

$(OBJ_DIR)%.o	  : $(SRC_DIR)%.c Makefile
			$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
			@echo "$(GREEN)file compiled$(NO_COLOR)"

$(OBJ_DIR):
	mkdir  $(OBJ_DIR)

#$(NAME) : $(TMP_OBJ) $(LIB)
#	$(CC) $(CFLAGS) $(TMP_OBJ) -L ./libft/ -lft -o $(NAME)
#	@echo "$(GREEN)librairy compiled and executable generated$(NO_COLOR)"


all: makelib $(OBJ_DIR) $(OBJSERVER) $(OBJCLIENT)
	$(MAKE) -C ./libft all
	$(CC) $(CFLAGS) $(SRCSERVER) -o $(SERVER) libft/libft.a
	$(CC) $(CFLAGS) $(SRCCLIENT) -o $(CLIENT) libft/libft.a

bonus: ${OBJSERVERBONUS} ${OBJCLIENTBONUS}
		$(MAKE) -C ./libft all
		$(CC) $(CFLAGS) $(SRCSERVERBONUS) -o $(SERVERBONUS) libft/libft.a
		$(CC) $(CFLAGS) $(SRCCLIENTBONUS) -o $(CLIENTBONUS) libft/libft.a	

server: $(OBJSERVER)
		$(MAKE) -C ./libft all
		$(CC) $(CFLAGS) $(SRCSERVER) -o $(SERVER) libft/libft.a

client: $(OBJCLIENT)
		$(MAKE) -C ./libft all
		$(CC) $(CFLAGS) $(SRCCLIENT) -o $(CLIENT) ftprintf/printf.a
clean :
		$(MAKE) -C ./libft clean
		$(RM) $(OBJSERVER)
	       	$(RM) $(OBJCLIENT)
		$(RM) $(OBJSERVERBONUS)
		$(RM) $(OBJCLIENTBONUS)	
		$(RM) $(OBJ_DIR)
			$(MAKE) clean -C $(LIB_DIR)
		@echo "$(RED)objects (*.o) removed$(NO_COLOR)"

fclean : clean
		$(MAKE) -C ./libft fclean	
		$(RM) $(LIB)
		$(RM) $(SERVER)
		$(RM) $(CLIENT)
		$(RM) $(SERVERBONUS)
		$(RM) $(CLIENTBONUS)
		@echo "$(RED)library (*.a) and executable removed $(NO_COLOR)"

re : fclean all
	@echo "$(YELLOW)make fclean  make all $(NO_COLOR)"

-include $(DEP) //
.PHONY : all clean fclean re bonus
