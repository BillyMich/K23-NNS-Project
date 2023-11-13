# paths
INCLUDE = ../include
MODULES = ../modules
DATASETS = ../datasets

# compiler
CC = gcc

# Compile options. Το -I<dir> tells to compiler where to find the include files
# -Werror when complite code add -Werror 
CFLAGS = -Wall  -g -I$(INCLUDE)
LDFLAGS = -lm -fsanitize=address -pthread

# .o files
OBJS = main.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o

# Executable
EXEC = program

# Args for examples
ARGSEUCL = $(DATASETS)/dummy2.bin 2 2 euclidean

ARGSMAN = $(DATASETS)/dummy2.bin 3 20 manhattan

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
	@if [ -f $(EXEC).exe ]; then ln -sf $(EXEC).exe $(EXEC); fi

clean:
	rm -f $(OBJS) $(EXEC)

run-euclidean: $(EXEC)
	./$(EXEC) $(ARGSEUCL)

run-manhattan: $(EXEC)
	./$(EXEC) $(ARGSMAN)

valgrind: $(EXEC)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(ARGSEUCL)