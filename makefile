# Compiler and Flags
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -w  # Suppress warnings with -w

# Source files
SRC = main.c menu.c simpleCalculator.c converters.c shapesIllustration.c \
      shapes.c list.c ageManipulation.c inputValidator.c baseN.c \
      numberManipulation.c matrixOperations.c vectors.c

# Object files
OBJ = $(SRC:.c=.o)

# Output executable
OUT = main.exe

# Default target
all: $(OUT)

# Rule to link the executable
$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(OUT)
