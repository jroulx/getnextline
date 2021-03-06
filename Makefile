NAME = get_next_line

CC = gcc

FLAG = -Werror -Wextra -Wall

SRC = get_next_line.c

OBJ = get_next_line.o

all : $(NAME)
	
$(NAME) :	
	$(CC) -c $(FLAG) $(SRC)
	$(CC) -o $(NAME) $(OBJ)

clean : 
	rm -rf $(OBJ)

val :
	$(CC) -g $(SRC)

fclean : clean
	rm -rf $(NAME)

re : fclean all