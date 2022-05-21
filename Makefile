NAME = snake

SRC = src/draw.c \
	  src/init.c \
	  src/movement.c \
	  src/snake.c

OBJ = $(SRC:.c=.o)

INC = -Iinc

LIB = lib/libny.a -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) $(INC) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB)

all: ${NAME}

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
