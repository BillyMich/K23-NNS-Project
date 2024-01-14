# paths
INCLUDE = ../include
MODULES = ../modules
DATASETS = ../datasets
TESTS = ../tests

# compiler
CC = gcc

CFLAGS = -Wall -Werror -g -I$(INCLUDE)
LDFLAGS = -lm

# .o files
OBJSKNN_IMP = $(TESTS)/knn_improvements_test.o $(MODULES)/Cost.o $(MODULES)/knn_improvements.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/knn.o $(MODULES)/projection_trees.o

OBJSKNN = $(TESTS)/knn_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/knn.o

OBJSG = $(TESTS)/graph_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/knn.o

OBJSN = $(TESTS)/nodes_test.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/Neighbors.o $(MODULES)/MathematicalFunctions.o 

OBJSD = $(TESTS)/dimension_test.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/Neighbors.o $(MODULES)/MathematicalFunctions.o

OBJSNEI = $(TESTS)/neighbours_test.o $(MODULES)/Neighbors.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o 

OBJSMATH = $(TESTS)/mathematical_test.o $(MODULES)/MathematicalFunctions.o $(MODULES)/Dimension.o

OBJSTREE = $(TESTS)/projection_trees_tests.o $(MODULES)/projection_trees.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/knn.o

OBJSK = $(TESTS)/knn_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o

# Executables
EXECKNN_IMP = knn_improvements_test

EXECKNN = knn_test

EXECG = graph_test

EXECN = nodes_test

EXECD = dimension_test

EXECNEI = neighbours_test

EXECMATH = mathFunctions_test

EXECTREES = projection_trees_tests

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

$(EXECTREES): $(OBJSTREE)
	$(CC) $(OBJSTREE) -o $(EXECTREES) $(LDFLAGS)

clean:
	rm -f $(OBJSG) $(OBJSN) $(OBJSD) $(OBJSKNN) $(OBJSKNN_IMP) $(OBJSMATH) $(OBJSNEI) $(EXECG) $(EXECN) $(EXECD) $(EXECKNN) $(EXECNEI) $(EXECMATH) $(EXECKNN_IMP) $(EXECTREES) $(OBJSTREE)
	
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

runTrees: $(EXECTREES)
	./$(EXECTREES)

run-all: runMath runG runN runD runNEI  runKNN runKNN_imp runTrees

valgrind-graph: $(EXECG)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXECG)

valgrind-dimension: $(EXECD)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXECD)

valgrind-node: $(EXECN)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXECN)

valgrind-neighbours: $(EXECNEI)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXECNEI)

valgrind-knn: $(EXECKNN)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXECKNN)

valgrind-knn-imp: $(EXECKNN_IMP)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXECKNN_IMP)

valgrind-trees: $(EXECTREES)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXECTREES)