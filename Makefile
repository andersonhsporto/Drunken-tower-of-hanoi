NAME	= DrunkHanoi

CC		= c++
CFLAGS	= -Wall -Wextra -Werror
INCLUDE =	-I ./
HEADERS	= Disk.hpp Player.hpp

SRC		= main.cpp Disk.cpp Player.cpp

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:%.cpp=%.o)

OBJ		= $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
