NAME		    =	BomberMan
SRC			    =	src/*.cpp
OBJ             =   $(SRCS:.cpp=.o)

CC              =   clang++ -std=gnu++11
CPPFLAGS        =   -Wall -Wextra -Werror
RM              =   rm -rf
DEPENDENCIES    = ./Build.sh
INCLUDES        = -I ~/.brew/include/SDL2
LIBS            = -L ~/.brew/lib/ -lSDL2 -lSDL2_image -lSDL2_ttf

all: $(NAME)

$(NAME): $(OBJ)
	$(DEPENDENCIES)
	$(CC) $(INCLUDES) $(LIBS) $(CPPFLAGS) $(SRC) -o $(NAME)
clean:
	$(RM)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
	
