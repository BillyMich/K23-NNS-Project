# paths
INCLUDE = ../include
MODULES = ../modules
DATASETS = ../datasets

# compiler
CC = gcc

# Compile options. Το -I<dir> tells to compiler where to find the include files
CFLAGS = -Wall -Werror -g -I$(INCLUDE)
LDFLAGS = -lm

# .o files
OBJS = main.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o

# Executable
EXEC = program

# Args for examples
ARGS2D = $(DATASETS)/dummy.bin 2

ARGS3D = $(DATASETS)/dummy.bin 3

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
	@if [ -f $(EXEC).exe ]; then ln -sf $(EXEC).exe $(EXEC); fi

clean:
	rm -f $(OBJS) $(EXEC)

run2D: $(EXEC)
	./$(EXEC) $(ARGS2D)

run3D: $(EXEC)
	./$(EXEC) $(ARGS3D)

valgrind: $(EXEC)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(ARGS)