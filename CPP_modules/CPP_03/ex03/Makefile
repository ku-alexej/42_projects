# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 15:29:24 by akurochk          #+#    #+#              #
#    Updated: 2024/07/15 19:02:30 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= DiamondTrap
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ_FOLDER	= .obj/
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