# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Ilib -Iincludes
LDFLAGS = 

# Directories
LIBDIR = lib
OBJDIR = obj

# Target executable
TARGET = z

# Source files
MAIN_SRC = main.c
LIB_SRCS = $(wildcard $(LIBDIR)/*.c)

# Object files
MAIN_OBJ = $(OBJDIR)/main.o
LIB_OBJS = $(LIB_SRCS:$(LIBDIR)/%.c=$(OBJDIR)/%.o)

# All object files
ALL_OBJS = $(MAIN_OBJ) $(LIB_OBJS)

# Default target
all: $(TARGET)

# Create target executable
$(TARGET): $(ALL_OBJS)
	$(CC) $(ALL_OBJS) -o $(TARGET) $(LDFLAGS)

# Compile main.c
$(MAIN_OBJ): $(MAIN_SRC) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

# Compile library source files
$(OBJDIR)/%.o: $(LIBDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create object directory
$(OBJDIR):
	mkdir $(OBJDIR)

# Clean build files
clean:
	rm -rf .$(OBJDIR)/ $(TARGET).exe

# Clean and rebuild
rebuild: clean all

# Show variables (for debugging)
debug:
	@echo "Library sources: $(LIB_SRCS)"
	@echo "Library objects: $(LIB_OBJS)"
	@echo "All objects: $(ALL_OBJS)"

# Phony targets
.PHONY: all clean rebuild debug