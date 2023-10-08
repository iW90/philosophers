# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 19:56:43 by inwagner          #+#    #+#              #
#    Updated: 2023/10/08 16:19:29 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		:=	philo

# Directories for source, object and libraries
HDR_DIR		:=	./incl
SRC_DIR		:=	./srcs
OBJ_DIR		:=	./objs

# Compilation flags
CFLAGS		:=	-Wall -Wextra -Werror -g -I $(HDR_DIR)

# Source files
FTS			:=	main.c \
				action_eat.c \
				action_sleep.c \
				action_think.c \
				exit.c \
				parser.c \
				start.c \
				time.c \
				utils.c \
				validators.c

# Object files
OBJ			:=	$(FTS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# Compile Objects
$(NAME): $(OBJ)
	@cc $(OBJ) -o $@

# Make Objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@cc $(CFLAGS) -c $< -o $@

clean:
	@[ -d $(OBJ_DIR) ] && rm -rf $(OBJ_DIR) || [ -f Makefile ]

fclean:	clean
	@[ -f ./$(NAME) ] && rm $(NAME) && echo $(NAME) cleaned ||  [ -f Makefile ]

re: fclean all

val: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} 2 2 2 2 || echo ""

vale: re
	@valgrind --tool=helgrind ./${NAME} 4 4 4 4 || echo ""

valy: re
	@valgrind --tool=drd ./${NAME} 4 4 4 4 || echo ""

.PHONY: all clean fclean re
