
# Define compiler
CC = gcc

# Define any compile-time flags
CFLAGS = -Wall -Werror -ansi -pedantic

# Define the target executable name
TARGET = image_editor
BIN = bin

# Define source files
SRCS = main.c image.c adjustment_func.c


compile:${SRCS}
	# $(CC) $(CFLAGS) -o $(BIN)/$(TARGET) $(SRCS)
	$(CC)  -o $(BIN)/$(TARGET) $(SRCS)

# Clean target
clean:
	rm -f $(TARGET) $(OBJS)

run: compile
	$(BIN)/$(TARGET) $(filename)

# Dependency
main.o: image.h
image.o: image.h
