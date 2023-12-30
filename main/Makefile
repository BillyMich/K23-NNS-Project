# paths
INCLUDE = ../include
MODULES = ../modules
DATASETS = ../datasets

# compiler
CC = gcc

# Compile options. Το -I<dir> tells to compiler where to find the include files
# -Werror when complite code add -Werror 
CFLAGS = -Wall -g -I$(INCLUDE)
LDFLAGS = -lm -fsanitize=address

# .o files
OBJS = main.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o $(MODULES)/knn_improvements.o $(MODULES)/Cost.o $(MODULES)/projection_trees.o

# Executable
EXEC = program

# Args for examples
ARGSEUCL = $(DATASETS)/1000000.bin 1000 500 euclidean 0.8 0.001 

ARGSMAN = $(DATASETS)/100000.bin 100 80 manhattan 0.1 0.001

ARGSIMP = $(DATASETS)/asciiData3.bin 10 50 improved 0.1 0.001 50

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
	@if [ -f $(EXEC).exe ]; then ln -sf $(EXEC).exe $(EXEC); fi

clean:
	rm -f $(OBJS) $(EXEC)
	rm *.txt

run-euclidean: $(EXEC)
	./$(EXEC) $(ARGSEUCL)

run-manhattan: $(EXEC)
	./$(EXEC) $(ARGSMAN)

run-euclidean-improved: $(EXEC)
	./$(EXEC) $(ARGSIMP)


valgrind: $(EXEC)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(ARGSEUCL)