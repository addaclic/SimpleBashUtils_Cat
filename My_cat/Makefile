PROJECT_NAME = My_cat
CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(PROJECT_NAME).c
	$(CC) $(FLAGS) $(PROJECT_NAME).c -o $(PROJECT_NAME)

clean:
	rm -f $(PROJECT_NAME)

style:
	clang-format -style=google -n *.c

test: