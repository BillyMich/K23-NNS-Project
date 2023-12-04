# Paths to source files
MAIN = main
MODULES = modules
DATASETS = datasets
TESTS = tests

# Paths to include files
INCLUDE = include

# Compiler
CC = gcc

# Compile options. The -I<dir> tells the compiler where to find the include files
# -Werror makes warnings errors
CFLAGS = -Wall -Werror -g -I$(INCLUDE)
LDFLAGS = -lm

# .o files
OBJS = $(MAIN)/main.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o $(MODULES)/knn_improvements.o $(MODULES)/Cost.o

# Test objects
OBJSKNN_IMP = $(TESTS)/knn_improvements_test.o $(MODULES)/Cost.o $(MODULES)/knn_improvements.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/knn.o
OBJSKNN = $(TESTS)/knn_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o
OBJSG = $(TESTS)/graph_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/knn.o
OBJSN = $(TESTS)/nodes_test.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/Neighbors.o $(MODULES)/MathematicalFunctions.o 
OBJSD = $(TESTS)/dimension_test.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/Neighbors.o $(MODULES)/MathematicalFunctions.o
OBJSNEI = $(TESTS)/neighbours_test.o $(MODULES)/Neighbors.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o 
OBJSMATH = $(TESTS)/mathematical_test.o $(MODULES)/MathematicalFunctions.o $(MODULES)/Dimension.o

# Executables
EXEC = program
EXECKNN_IMP = knn_improvements_test
EXECKNN = knn_test
EXECG = graph_test
EXECN = nodes_test
EXECD = dimension_test
EXECNEI = neighbours_test
EXECMATH = mathFunctions_test

# Args for examples
ARGSEUCL = $(DATASETS)/00001000-4.bin 100 399 euclidean 0.2 0.001
ARGSMAN = $(DATASETS)/00001000-4.bin 100 399 manhattan 0.1 0.001

run-euclidean: $(EXEC)
	./$(EXEC) $(ARGSEUCL)

run-manhattan: $(EXEC)
	./$(EXEC) $(ARGSMAN)

runKNN_imp: $(EXECKNN_IMP)
	./$(EXECKNN_IMP)

runKNN: $(EXECKNN)
	./$(EXECKNN)

runG: $(EXECG)
	./$(EXECG)

runN: $(EXECN)
	./$(EXECN)

runD: $(EXECD)
	./$(EXECD)

runNEI: $(EXECNEI)
	./$(EXECNEI)

runMath: $(EXECMATH)
	./$(EXECMATH)


# for every .c file
all: run-euclidean run-manhattan runKNN_imp runKNN runG runN runD runNEI runMath

# for 2 "main"
main-all: run-euclidean run-manhattan

# for all tests
run-all-tests: runKNN_imp runKNN runG runN runD runNEI runMath

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
	@if [ -f $(EXEC).exe ]; then ln -sf $(EXEC).exe $(EXEC); fi

$(EXECKNN_IMP): $(OBJSKNN_IMP)
	$(CC) $(OBJSKNN_IMP) -o $(EXECKNN_IMP) $(LDFLAGS)

$(EXECKNN): $(OBJSKNN)
	$(CC) $(OBJSKNN) -o $(EXECKNN) $(LDFLAGS)

$(EXECG): $(OBJSG)
	$(CC) $(OBJSG) -o $(EXECG) $(LDFLAGS)

$(EXECN): $(OBJSN)
	$(CC) $(OBJSN) -o $(EXECN) $(LDFLAGS)

$(EXECD): $(OBJSD)
	$(CC) $(OBJSD) -o $(EXECD) $(LDFLAGS)

$(EXECNEI): $(OBJSNEI)
	$(CC) $(OBJSNEI) -o $(EXECNEI) $(LDFLAGS)

$(EXECMATH): $(OBJSMATH)
	$(CC) $(OBJSMATH) -o $(EXECMATH) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(EXEC) $(OBJSG) $(OBJSN) $(OBJSD) $(OBJSKNN) $(OBJSMATH) $(OBJSNEI) $(EXECG) $(EXECN) $(EXECD) $(EXECKNN) $(EXECNEI) $(EXECMATH) $(OBJSKNNIMP) $(EXECMATH) $(EXECKNN_IMP) $(OBJSKNN_IMP)
	rm *.txt