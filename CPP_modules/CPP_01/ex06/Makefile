# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 17:36:02 by akurochk          #+#    #+#              #
#    Updated: 2024/07/10 18:06:57 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= harlFilter
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp Harl.cpp
OBJ_FOLDER	= obj/
OBJ			= $(addprefix $(OBJ_FOLDER), $(SRC:.cpp=.o))

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_FOLDER)%.o: %.cpp
			@mkdir -p $(OBJ_FOLDER)
			$(CC) $(CPPFLAGS) -c $< -o $@

clean:
			rm -rf $(OBJ_FOLDER)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re