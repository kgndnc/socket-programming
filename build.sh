#!/bin/bash

PROJECT_ROOT=$(pwd)

# Create bin directory if it doesn't exist
mkdir -p "$PROJECT_ROOT/bin"

# Find all .c files in the current directory and compile them
for file in *.c; do
    # Check if files exist to avoid errors if no .c files are found
    if [ -f "$file" ]; then
        # Extract the base filename without extension
        base_name="${file%.c}"
        
        # Compile the file
        echo "Compiling $file to bin/$base_name"
        gcc "$file" -o "$PROJECT_ROOT/bin/$base_name"
    fi
done
