# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 19:56:43 by inwagner          #+#    #+#              #
#    Updated: 2023/10/21 13:40:26 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		:=	philo_bonus
RUN			:=	philo_bonus 5 800 200 200 5

# Directories for source, object and libraries
HDR_DIR		:=	./incl
SRC_DIR		:=	./srcs
OBJ_DIR		:=	./objs

# Compilation flags
CFLAGS		:=	-Wall -Wextra -Werror -g -I $(HDR_DIR)

# Source files
FTS			:=	main.c \
				actions.c \
				childs.c \
				father.c \
				finish.c \
				parser.c \
				utils.c \
				validators.c

# Object files
OBJ			:=	$(FTS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# Compile Objects
$(NAME): $(OBJ)
	@cc $(OBJ) -lpthread -o $@

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
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} || echo ""

hel: re
	@valgrind --tool=helgrind ./${RUN} || echo ""

drd: re
	@valgrind --tool=drd ./${RUN} || echo ""

.PHONY: all clean fclean re
