# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 14:39:06 by akurochk          #+#    #+#              #
#    Updated: 2023/10/17 13:06:31 by akurochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
OBJ_DIR			=	obj/
SRC_DIR			=	src/
HEADERS			=	-I inc/
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
RM				=	rm

LIBFT_DIR		=	libft/
LIBFT_FILES		=	ft_isalpha ft_memchr  ft_memset ft_strlen ft_tolower \
					ft_strrchr ft_atoi ft_isascii ft_memcmp ft_strchr \
					ft_strncmp ft_toupper ft_bzero ft_isdigit ft_memcpy \
					ft_strlcat ft_strnstr ft_isalnum ft_isprint ft_memmove \
					ft_strlcpy ft_calloc ft_strdup ft_itoa ft_putchar_fd \
					ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split ft_striteri \
					ft_strjoin ft_strmapi ft_strtrim ft_substr ft_lstadd_back \
					ft_lstclear ft_lstiter ft_lstmap ft_lstsize ft_lstadd_front \
					ft_lstdelone ft_lstlast ft_lstnew

PRINTF_DIR		=	ft_printf/
PRINTF_FILES	= 	ft_parse_format ft_print_c ft_print_d ft_print_p ft_print_percent \
					ft_print_s ft_print_u ft_print_x_lower ft_print_x_upper ft_printf \
					ft_utils_count ft_utils_put

GNL_DIR			=	gnl/
GNL_FILES		=	get_next_line

SRC_FILES		+=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILES))
SRC_FILES		+=	$(addprefix $(PRINTF_DIR), $(PRINTF_FILES))
SRC_FILES		+=	$(addprefix $(GNL_DIR), $(GNL_FILES))

SRCS 			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: 		$(NAME)

$(NAME): 	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(LIBFT_DIR)
			@mkdir -p $(OBJ_DIR)$(PRINTF_DIR)
			@mkdir -p $(OBJ_DIR)$(GNL_DIR)
			$(CC) $(FLAGS) -g $(HEADERS) -c $< -o $@

clean:
			$(RM) -fr $(OBJ_DIR)

fclean: 	clean
			$(RM) -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re