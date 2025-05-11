##------------------------------------------------------------------##
# Variables.
## Name(s)
NAME			= megaphone

## Sources & headers & others
SRC				= megaphone.cpp

## Compiler, flags, & other commands
CPP				= c++
CPPFLAGS		= -Wall -Wextra -Werror
RM				= rm -rf
SRC = megaphone.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

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

test:			re
	./megaphone "shhhhh... I think the students are asleep..."
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
	./megaphone

##------------------------------------------------------------------##
# Targets
$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CPP) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re