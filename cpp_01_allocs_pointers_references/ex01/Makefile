##------------------------------------------------------------------##
# Variables.
## Name(s)
NAME			= horde

## Sources & headers & objects
SRC				= main.cpp \
					Zombie.cpp \
					ZombieHorde.cpp
OBJ_DIR			= obj
OBJ				= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

## Compiler, flags, & other commands
CPP				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
RM				= rm -rf

## Text colors
RED					=	\033[1;31m
GREEN				=	\033[1;32m
YELLOW				=	\033[1;33m
COLOFF				=	\033[0m

##------------------------------------------------------------------##
# Build rules
all: 			$(NAME)

clean:
				@$(RM) $(OBJ_DIR)
				@$(RM) $(NAME)

fclean: 		clean

re:				fclean all

##------------------------------------------------------------------##
# Targets
$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CPP) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re