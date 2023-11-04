# Paths to source files
SRC_MAIN = main
SRC_MODULES = modules
SRC_DATASETS = datasets
SRC_TESTS = tests

# Paths to include files
INCLUDE = include

# Compiler
CC = gcc

# Compile options. The -I<dir> tells the compiler where to find the include files
# -Werror makes warnings errors
CFLAGS = -Wall -Werror -g -I$(INCLUDE)
LDFLAGS = -lm -fsanitize=address

# .o files
OBJS = $(SRC_MAIN)/main.o $(SRC_MODULES)/Graph.o $(SRC_MODULES)/Node.o $(SRC_MODULES)/Neighbors.o $(SRC_MODULES)/Dimension.o $(SRC_MODULES)/MathematicalFunctions.o $(SRC_MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o

# Test objects
OBJSG = $(SRC_TESTS)/graph_test.o $(SRC_MODULES)/Graph.o $(SRC_MODULES)/Node.o $(SRC_MODULES)/Neighbors.o $(SRC_MODULES)/Dimension.o $(SRC_MODULES)/MathematicalFunctions.o $(SRC_MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o
OBJSN = $(SRC_TESTS)/nodes_test.o $(SRC_MODULES)/Node.o $(SRC_MODULES)/Dimension.o $(SRC_MODULES)/Neighbors.o $(SRC_MODULES)/MathematicalFunctions.o $(SRC_MODULES)/FindAllRightNeighborsAlgorithm.o
OBJSD = $(SRC_TESTS)/dimension_test.o $(SRC_MODULES)/Node.o $(SRC_MODULES)/Dimension.o $(SRC_MODULES)/Neighbors.o $(SRC_MODULES)/MathematicalFunctions.o $(SRC_MODULES)/FindAllRightNeighborsAlgorithm.o

# Executables
EXEC = program
EXECG = graph_test
EXECN = nodes_test
EXECD = dimension_test

# Args for examples
ARGS2D = $(SRC_DATASETS)/dummy.bin 2 2
ARGS3D = $(SRC_DATASETS)/dummy2.bin 4 4
ARGSMAKEFILE = $(SRC_DATASETS)/dummy2.bin

all: $(EXEC) $(EXECG) $(EXECN) $(EXECD)

run: $(EXEC)
	./$(EXEC) $(ARGS2D)

runG: $(EXECG)
	./$(EXECG) $(ARGS)

runN: $(EXECN)
	./$(EXECN) $(ARGS)

runD: $(EXECD)
	./$(EXECD)

run-all: run runG runN runD

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
	@if [ -f $(EXEC).exe ]; then ln -sf $(EXEC).exe $(EXEC); fi

$(EXECG): $(OBJSG)
	$(CC) $(OBJSG) -o $(EXECG) $(LDFLAGS)

$(EXECN): $(OBJSN)
	$(CC) $(OBJSN) -o $(EXECN) $(LDFLAGS)

$(EXECD): $(OBJSD)
	$(CC) $(OBJSD) -o $(EXECD) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(OBJSG) $(OBJSN) $(OBJSD) $(EXEC) $(EXECG) $(EXECN) $(EXECD)
