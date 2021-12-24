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

SRC = $(wildcard $(FT_PRINTF)/*.c) minitalk_utils.c

SRCOBJ = ${SRC:.c=.o}

INCLUDE1 = $(wildcard $(FT_PRINTF)/*.h)
INCLUDE2 = minitalk.h

CC = cc 

FLAGS = -Wall -Wextra -Werror

%.o : %.c ${INCLUDE1} 
	@${CC} ${FLAGS} -c $< -o $@
	@echo "==> We compiled the file $<  :>"

$(NAME) : ${SRCOBJ} ${INCLUDE1} ${INCLUDE2}
	@ar rcs ${NAME} ${SRCOBJ} 
	@echo "\n==> We have just made your libftprintf.a library !\n"
	

all : $(NAME)  
	@${CC} ${FLAGS} $(NAME) server.c -o server
	@${CC} ${FLAGS} $(NAME) client.c -o client
	@echo "==> We created the server and the client ;)\n"

server: ${SRCOBJ} ${INCLUDE1} ${INCLUDE2}
	@ar rcs ${NAME} ${SRCOBJ} 
	@echo "\n==> We have just made your libftprintf.a library !\n"
	@${CC} ${FLAGS} $(NAME) server.c -o server
	@echo "\n==> We created the server ;)\n"

client: ${SRCOBJ} ${INCLUDE1} ${INCLUDE2}
	@ar rcs ${NAME} ${SRCOBJ} 
	@echo "\n==> We have just made your libftprintf.a library !\n"
	@${CC} ${FLAGS} $(NAME) client.c -o client
	@echo "\n==> We created the client ;)\n"

clean :
	@rm -f ${wildcard $(FT_PRINTF)/*.o} *.o
	@echo "\n==> We deleted all the files *.o in ft_printf directory o_o\n"

fclean : clean
	@rm -f ${NAME} server client
	@echo "==> We deleted the server, the client and libftprintf.a *_*\n"

re : fclean all
