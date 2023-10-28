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
OBJSG = $(TESTS)/graph_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o

OBJSN = $(TESTS)/nodes_test.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/Neighbors.o

# Executables
EXECG = graph_test

EXECN = nodes_test

ARGS = 

$(EXECG): $(OBJSG)
	$(CC) $(OBJSG) -o $(EXECG) $(LDFLAGS)

$(EXECN): $(OBJSN)
	$(CC) $(OBJSN) -o $(EXECN) $(LDFLAGS)

clean:
	rm -f $(OBJSG) $(OBJSN) $(EXECG) $(EXECN)

runG: $(EXECG)
	./$(EXECG) $(ARGS)

runN: $(EXECN)
	./$(EXECN) $(ARGS)

valgrind: $(EXECG)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXECG)