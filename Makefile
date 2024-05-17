NAME = BankingSystem
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
SRC = src/*.c
INCLUDES = includes/*.h
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	printf "\033[32m[✔] %s\n\033[0m" "Create BankingSystem"

clean:
	$(RM) $(OBJ)
	printf "\033[31m[✔] %s\n\033[0m" "Clean BankingSystem"

fclean: clean
	$(RM) $(NAME)
	printf "\033[31m[✔] %s\n\033[0m" "Fclean BankingSystem"

re: fclean all

.PHONY: all clean fclean re