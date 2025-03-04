## EPITECH PROJECT, 2024
## Makefile Root
## File description:
## MakeFile in the root directory

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
NC=\033[0m # No Color

# Variables
NAME = asm
CFLAGS = -g -Wall -Wextra -W -Iinclude -Ilib/include -fdiagnostics-color=always
SRC =	./src/robot_factory.c \
        ./src/create_champions.c \
        ./src/error_handling.c \
        ./src/champion_parsing.c \
        ./src/create_cor.c
OBJ = $(SRC:.c=.o)
LIBMY = libmy.a

# Default target
all: $(LIBMY) $(NAME)

# Compilation of the main executable
$(NAME): $(OBJ)
	@echo "$(YELLOW)Building $@...$(NC)"
	@OUTPUT=$$(gcc $(CFLAGS) -o $@ $^ $(LIBMY) 2>&1); \
	ERRORS=$$(echo "$$OUTPUT" | grep -c "error:"); \
	WARNINGS=$$(echo "$$OUTPUT" | grep -c "warning:"); \
	if [ $$ERRORS -eq 0 ]; then \
		echo "$(GREEN)Build complete!$(NC)"; \
	else \
		echo "$(RED)Build failed with $$ERRORS errors$(MAGENTA) and $$WARNINGS warnings!$(NC)"; \
	fi

# Compilation of object files
%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@ || { \
		echo "$(RED)BUILD FAILED!$(NC)"; \
		exit 1; \
	}

# Compilation of the library
$(LIBMY):
	@echo "$(BLUE)Building library...$(NC)"
	@$(MAKE) --no-print-directory -C lib all

# Clean up object files and executables
clean:
	@echo "$(RED)Cleaning up...$(NC)"
	@$(MAKE) --no-print-directory -C lib clean
	@rm -f $(OBJ)

# Full clean up
fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBMY)

# Rebuild everything
re: fclean all

# Debug mode
debug: CFLAGS += -g
debug: $(NAME)

# Rebuild in debug mode
redebug: fclean debug

# Phony targets
.PHONY: all clean fclean re debug redebug
