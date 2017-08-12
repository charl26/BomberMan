NAME		    =	BomberMan
SRC			    =	src/*.cpp
OBJ             =   $(SRCS:.cpp=.o)

CC              =   clang++ -std=gnu++11
CPPFLAGS        =   -Wall -Wextra -Werror
RM              =   rm -rf
DEPENDENCIES    = ./Build.sh

all: $(NAME)

$(NAME): $(OBJ)
	$(DEPENDENCIES)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)
clean:
	$(RM)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all