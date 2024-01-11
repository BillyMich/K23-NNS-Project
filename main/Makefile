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

OBJSAccuarion = accuration.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o $(MODULES)/FindAllRightNeighborsAlgorithm.o $(MODULES)/knn.o $(MODULES)/knn_improvements.o $(MODULES)/Cost.o
# Executable
EXEC = program

EXECAccuration = programAccuration


# Args for examples

ARGSEUCL = $(DATASETS)/1000000.bin 500 100 euclidean 0.4 0.002050

ARGSMAN =  $(DATASETS)/1000000.bin 100 100  manhattan 0.9 0.1

ARGSEUCL = $(DATASETS)/1000000.bin 1000 500 euclidean 0.8 0.001 50

ARGSMAN = $(DATASETS)/100000.bin 100 80 manhattan 0.1 0.001 50

ARGSIMP = $(DATASETS)/asciiData3.bin 10 50 improved 0.1 0.001 50



$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
	@if [ -f $(EXEC).exe ]; then ln -sf $(EXEC).exe $(EXEC); fi

$(EXECAccuration): $(OBJSAccuarion)
	$(CC) $(OBJSAccuarion) -o $(EXECAccuration) $(LDFLAGS)
	@if [ -f $(EXECAccuration).exe ]; then ln -sf $(EXECAccuration).exe $(EXECAccuration); fi	

clean:
	rm -f $(OBJS) $(EXEC) $(EXECAccuration) *.o *.exe *.stackdump *.out *.bin *.txt
	rm *.txt

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