##
## EPITECH PROJECT, 2022
## my_hunter
## File description:
## makefile
##

CC = gcc
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = slime_defender

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $@ $(OBJ) -lcsfml-graphics -lcsfml-system -lm

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)

re : fclean all
