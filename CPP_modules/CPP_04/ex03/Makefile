# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 13:29:07 by akurochk          #+#    #+#              #
#    Updated: 2024/07/18 12:51:12 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the binary
NAME = interface

# sources needed to compile
SRC =	main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

# path of sources
PATH_SRCS = ./srcs

# pathe of includes
INCLUDES =	./includes/

# flags for compilation
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# compiler used
CXX = c++

##########################################

SRCS = $(addprefix $(PATH_SRCS)/,$(SRC))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
OBJ_DIR = .obj

all: $(NAME)

$(OBJ_DIR)/%.o: $(PATH_SRCS)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) $(OBJ) -o $(NAME)
	@chmod 777 $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
