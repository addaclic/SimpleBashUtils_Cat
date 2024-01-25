PROJECT_NAME = My_grep
CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(PROJECT_NAME).c
	$(CC) $(FLAGS) $(PROJECT_NAME).c -o $(PROJECT_NAME)

clean:
	rm -f $(PROJECT_NAME) *.log

style:
	clang-format -style=google -n *.c

test: $(PROJECT_NAME)
	bash test_func_grep.sh