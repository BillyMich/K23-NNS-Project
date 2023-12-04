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
OBJSKNN = $(TESTS)/knn_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o
OBJSKNNIMP = $(TESTS)/knn_improvements_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o $(MODULES)/knn_improvements.o $(MODULES)/Cost.o
OBJSG = $(TESTS)/graph_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/knn.o
OBJSN = $(TESTS)/nodes_test.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/Neighbors.o $(MODULES)/MathematicalFunctions.o 
OBJSD = $(TESTS)/dimension_test.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/Neighbors.o $(MODULES)/MathematicalFunctions.o
OBJSNEI = $(TESTS)/neighbours_test.o $(MODULES)/Neighbors.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o 
OBJSMATH = $(TESTS)/mathematical_test.o $(MODULES)/MathematicalFunctions.o $(MODULES)/Dimension.o

# Executables
EXEC = program
EXECKNN = knn_test
EXECKNNImp = knn_improvements_test
EXECG = graph_test
EXECN = nodes_test
EXECD = dimension_test
EXECNEI = neighbours_test
EXECMATH = mathFunctions_test

# Args for examples
ARGSEUCL = $(DATASETS)/00000020.bin 10 65 euclidean 0.8 0.001
ARGSMAN = $(DATASETS)/00001000-4.bin 100 399 manhattan 0.1 0.001

all: $(EXEC) $(EXECG) $(EXECN) $(EXECD)

run-euclidean: $(EXEC)
	./$(EXEC) $(ARGSEUCL)

run-manhattan: $(EXEC)
	./$(EXEC) $(ARGSMAN)

runKNN: $(EXECKNN)
	./$(EXECKNN)

runKNNImp: $(EXECKNNImp)
	./$(EXECKNNImp)

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

run-all: run-euclidean run-manhattan runKNN runKNNImp runG runN runD runNEI runMath

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
	@if [ -f $(EXEC).exe ]; then ln -sf $(EXEC).exe $(EXEC); fi

$(EXECKNN): $(OBJSKNN)
	$(CC) $(OBJSKNN) -o $(EXECKNN) $(LDFLAGS)

$(EXECKNNImp): $(OBJSKNNIMP)
	$(CC) $(OBJSKNNIMP) -o $(EXECKNNImp) $(LDFLAGS)

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
	rm -f $(OBJS) $(EXEC) $(OBJSG) $(OBJSN) $(OBJSD) $(OBJSKNN) $(OBJSMATH) $(OBJSNEI) $(EXECG) $(EXECN) $(EXECD) $(EXECKNN) $(EXECNEI) $(EXECMATH)  $(EXECKNNImp) $(OBJSKNNIMP)
	rm *.txt