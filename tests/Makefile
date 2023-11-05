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
OBJSKNN = $(TESTS)/knn_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/knn.o

OBJSG = $(TESTS)/graph_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/knn.o

OBJSN = $(TESTS)/nodes_test.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/Neighbors.o $(MODULES)/MathematicalFunctions.o 

OBJSD = $(TESTS)/dimension_test.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/Neighbors.o $(MODULES)/MathematicalFunctions.o

OBJSNEI = $(TESTS)/neighbours_test.o $(MODULES)/Neighbors.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o 

OBJSMATH = $(TESTS)/mathematical_test.o $(MODULES)/MathematicalFunctions.o $(MODULES)/Dimension.o


# Executables
EXECKNN = knn_test

EXECG = graph_test

EXECN = nodes_test

EXECD = dimension_test

EXECNEI = neighbours_test

EXECMATH = mathFunctions_test

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
	rm -f $(OBJSG) $(OBJSN) $(OBJSD) $(OBJSKNN) $(OBJSMATH) $(OBJSNEI) $(EXECG) $(EXECN) $(EXECD) $(EXECKNN) $(EXECNEI) $(EXECMATH)

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

run-all: runKNN runG runN runD runNEI runMath

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