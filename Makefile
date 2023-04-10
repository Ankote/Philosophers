NAME = philo

SRC = philo.c time.c events.c

OBJS = $(SRC:.c=.o)

CFLAGS  = -Wall -Wextra -Werror #-fsanitize=thread

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "\033[0;32mCompiling philosophers..."
	@$(CC)  $(OBJS) $(CFLAGS)  -o $(NAME)
	@echo "\n\x1b[34mDone !\033[0m"

%.o:%.c
	@printf "\033[0;33mGenerating philo objects... %-33.33s\r" $@
	@$(CC)  $(CFLAGS) -c $<  -o $@

clean :
	@echo "\033[0;31m"
	@echo "\nRemoving binaries..."
	@rm -fr $(OBJS)
	@echo "\033[0;31m𝑶𝒃𝒋𝒆𝒄𝒕𝒔' 𝒄𝒍𝒆𝒂𝒏𝒆𝒅\033[0m"
	@echo "\033[0m"

fclean : clean
	@echo "\033[0;31m"
	@echo "\nDeleting objects..."
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re :fclean all

push : fclean
	git add .
	git commit -m "Updated"
	git push