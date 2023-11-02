# paths
INCLUDE = ../include
MODULES = ../modules
DATASETS = ../datasets

# compiler
CC = gcc

# Compile options. Το -I<dir> tells to compiler where to find the include files
# -Werror when complite code add -Werror 
CFLAGS = -Wall  -g -I$(INCLUDE)
LDFLAGS = -lm -fsanitize=address

# .o files
OBJS = main.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o

# Executable
EXEC = program

# Args for examples
ARGS2D = $(DATASETS)/dummy.bin 2 2

ARGSEUCL = $(DATASETS)/dummy.bin 2 2 euclidean

ARGSMAN = $(DATASETS)/dummy.bin 2 2 manhattan

ARGSMAKEFILE = $(DATASETS)/dummy2.bin 

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
	@if [ -f $(EXEC).exe ]; then ln -sf $(EXEC).exe $(EXEC); fi

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS2D)

run-euclidean: $(EXEC)
	./$(EXEC) $(ARGSEUCL)

run-manhattan: $(EXEC)
	./$(EXEC) $(ARGSMAN)

runM: $(EXEC)
	./$(EXEC) $(ARGSMAKEFILE)

valgrind: $(EXEC)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(ARGS2D)