# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 12:42:37 by akurochk          #+#    #+#              #
#    Updated: 2023/10/02 17:25:30 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C			= client
NAME_S			= server
NAME_CB			= client_bonus
NAME_SB			= server_bonus
LIB_DIR			= libs
SRC_DIR			= src/
OBJ_DIR			= obj/
HEADERS			= -I inc
LIBFT			= $(LIB_DIR)/libft.a
CC				= gcc
FLAGS			= -Wall -Wextra -Werror
RM				= rm

CLIENT_FILES	=	client
SERVER_FILES	=	server
CLIENT_BONUS	=	client_bonus
SERVER_BONUS	=	server_bonus

SRC_C 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CLIENT_FILES)))
OBJ_C 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLIENT_FILES)))

SRC_S 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SERVER_FILES)))
OBJ_S 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SERVER_FILES)))

SRC_CB 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CLIENT_BONUS)))
OBJ_CB			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLIENT_BONUS)))

SRC_SB 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SERVER_BONUS)))
OBJ_SB 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SERVER_BONUS)))

all:		$(NAME_C) $(NAME_S)

$(NAME_C):	$(OBJ_C)
			@make -C $(LIB_DIR)
			@mkdir -p $(OBJ_DIR)
			$(CC) $(FLAGS) -g $(OBJ_C) $(HEADERS) $(LIBFT) -o $(NAME_C)

$(NAME_S):	$(OBJ_S) 
			@make -C $(LIB_DIR)
			@mkdir -p $(OBJ_DIR)
			$(CC) $(FLAGS) -g $(OBJ_S) $(HEADERS) $(LIBFT) -o $(NAME_S)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
			@mkdir -p $(OBJ_DIR)
			$(CC) $(FLAGS) -g $(HEADERS) -c $< -o $@

bonus:
			@make -C $(LIB_DIR)
			@mkdir -p $(OBJ_DIR)
			@make $(NAME_CB)
			@make $(NAME_SB)

$(NAME_CB):	$(OBJ_CB)
			$(CC) $(FLAGS) -g $(OBJ_CB) $(HEADERS) $(LIBFT) -o $(NAME_CB)

$(NAME_SB):	$(OBJ_SB) 
			$(CC) $(FLAGS) -g $(OBJ_SB) $(HEADERS) $(LIBFT) -o $(NAME_SB)

clean:
			$(RM) -fr $(OBJ_DIR)
			make clean -C $(LIB_DIR)

fclean:		clean
			$(RM) -f $(NAME_C) $(NAME_S) $(NAME_CB) $(NAME_SB)
			$(RM) -f $(LIBFT)
			$(RM) -f libft.a

re:			fclean all

.PHONY:		all clean fclean re bonus
