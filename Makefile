# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 14:29:53 by hboumahd          #+#    #+#              #
#    Updated: 2021/11/27 14:29:57 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FT_PRINTF= ./ft_printf
BONUS= ./bonus

SRC = $(wildcard $(FT_PRINTF)/*.c) $(wildcard $(BONUS)/*.c) minitalk_utils.c server.c  client.c 

SRCOBJ = ${SRC:.c=.o}

INCLUDE1 = $(wildcard $(FT_PRINTF)/*.h)
INCLUDE2 = minitalk.h

CC = cc 

FLAGS = -Wall -Wextra -Werror

%.o : %.c ${INCLUDE1} ${INCLUDE2}
	@${CC} ${FLAGS} -c $< -o $@
	@echo "==> compile  the file $< "

$(NAME) : ${SRCOBJ} ${INCLUDE1} ${INCLUDE2}
	@ar rcs ${NAME} ${SRCOBJ} 
	@echo "\n ✅ ==> We have just made your libftprintf.a library !\n"
	

all : $(NAME)  
	@${CC} ${FLAGS} $(NAME) server.c -o server
	@${CC} ${FLAGS} $(NAME) client.c -o client
	@echo " ✅ ==> We created the server and the client ;)\n"

server: $(NAME)
	@${CC} ${FLAGS} $(NAME) server.c -o server
	@echo "\n ✅ ==> We created the server ;)\n"

client: $(NAME)
	@${CC} ${FLAGS} $(NAME) client.c -o client
	@echo "\n ✅ ==> We created the client ;)\n"

bonus: $(NAME)  
	@${CC} ${FLAGS} $(NAME) ./bonus/server_bonus.c -o server_bonus
	@${CC} ${FLAGS} $(NAME) ./bonus/client_bonus.c -o client_bonus
	@echo " ✅ ==> We created the server_bonus and the client_bonus ;)\n"

clean :
	@rm -f ./ft_printf/*.o *.o ./bonus/*.o
	@echo "\n 📛 ==> We deleted :\n    all the files that ends with .o  o_o\n"

fclean : clean
	@rm -f ${NAME} server client server_bonus client_bonus
	@echo " 📛 ==> We deleted :\n    all executable files and libftprintf.a *_*\n"

re : fclean all
