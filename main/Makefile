# paths
INCLUDE = ../include
MODULES = ../modules
DATASETS = ../datasets

# compiler
CC = gcc

# Compile options. Το -I<dir> tells to compiler where to find the include files
# -Werror when complite code add -Werror 

CFLAGS = -Wall -Werror -g -I$(INCLUDE)
LDFLAGS = -lm -fsanitize=address -lpthread


# .o files
OBJS = main.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o $(MODULES)/knn_improvements.o $(MODULES)/Cost.o $(MODULES)/projection_trees.o

OBJSAccuarion = accuration.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o $(MODULES)/knn_improvements.o $(MODULES)/Cost.o $(MODULES)/projection_trees.o
# Executable
EXEC = program

EXECAccuration = programAccuration


# Args for examples

ARGSEUCL = $(DATASETS)/asciiData3.bin 5 20 improved 0.5 0.019 30 1

ARGSMAN = $(DATASETS)/asciiData3.bin 5 20 improved 0.5 0.019 30 1

ARGSIMP = $(DATASETS)/asciiData3.bin 5 20 improved 0.6 0.0151 30 1



$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
	@if [ -f $(EXEC).exe ]; then ln -sf $(EXEC).exe $(EXEC); fi

$(EXECAccuration): $(OBJSAccuarion)
	$(CC) $(OBJSAccuarion) -o $(EXECAccuration) $(LDFLAGS)
	@if [ -f $(EXECAccuration).exe ]; then ln -sf $(EXECAccuration).exe $(EXECAccuration); fi	

clean:
	rm -f $(OBJS) $(EXEC) $(EXECAccuration) *.o *.exe *.stackdump *.out *.bin *.txt
	rm txtfiles/*.txt

run-euclidean: $(EXEC)
	./$(EXEC) $(ARGSEUCL)

run-accuration: $(EXECAccuration)
	./$(EXECAccuration)

run-manhattan: $(EXEC)
	./$(EXEC) $(ARGSMAN)

run-euclidean-improved: $(EXEC)
	./$(EXEC) $(ARGSIMP)


valgrind: $(EXEC)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(ARGSIMP)