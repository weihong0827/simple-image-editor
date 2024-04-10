# Define compiler
CC = gcc

# Define any compile-time flags
CFLAGS = -Wall -Werror -ansi -pedantic 
IFLAGS = -Iinclude -MMD -MP
# Define the target executable name
TARGET = image_editor
SRC_DIR := src
OBJ_DIR := obj
BIN := bin

# Define source files
# SRCS = main.c image.c adjustment_func.c
SRCS := $(wildcard $(SRC_DIR)/*.c)

compile:${SRCS}
	# $(CC) $(CFLAGS) -o $(BIN)/$(TARGET) $(SRCS)
	$(CC) $(IFLAGS) `pkg-config --cflags --libs gtk+-3.0` -o $(BIN)/$(TARGET) $(SRCS)

# Clean target
clean:
	rm -f $(TARGET) $(OBJS)

run: compile
	$(BIN)/$(TARGET) $(filename)

# Dependency
main.o: image.h
image.o: image.h
