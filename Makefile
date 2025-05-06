# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Find all C files in the current directory
SOURCES = $(wildcard *.c)

# Create a list of executable names (same as source files but without .c extension)
EXECUTABLES = $(SOURCES:.c=)

# Default target - builds all executables
all: $(EXECUTABLES)

# Pattern rule to build an executable from a C file
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Clean up all executables
clean:
	rm -f $(EXECUTABLES)

# Phony targets
.PHONY: all clean