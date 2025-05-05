# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Source files
SRCS = showip.c socket.c client.c tcpserver.c

# Executable names (same as source files without the .c extension)
EXECS = showip socket client tcpserver

# Default target builds all executables
all: $(EXECS)

# Generic rule to build executables from C files
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up
clean:
	rm -f $(EXECS)

# Phony targets
.PHONY: all clean
