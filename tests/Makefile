# paths
INCLUDE = ../include
MODULES = ../modules
DATASETS = ../datasets
TESTS = ../tests

# compiler
CC = gcc

CFLAGS = -Wall -Werror -g -I$(INCLUDE)
LDFLAGS = -lm -fsanitize=address

# .o files
OBJSG = $(TESTS)/graph_test.o $(MODULES)/Graph.o $(MODULES)/Node.o $(MODULES)/Neighbors.o $(MODULES)/Dimension.o $(MODULES)/MathematicalFunctions.o

OBJSN = $(TESTS)/nodes_test.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/Neighbors.o $(MODULES)/MathematicalFunctions.o

OBJSD = $(TESTS)/dimension_test.o $(MODULES)/Node.o $(MODULES)/Dimension.o $(MODULES)/Neighbors.o $(MODULES)/MathematicalFunctions.o

# Executables
EXECG = graph_test

EXECN = nodes_test

EXECD = dimension_test

$(EXECG): $(OBJSG)
	$(CC) $(OBJSG) -o $(EXECG) $(LDFLAGS)

$(EXECN): $(OBJSN)
	$(CC) $(OBJSN) -o $(EXECN) $(LDFLAGS)

$(EXECD): $(OBJSD)
	$(CC) $(OBJSD) -o $(EXECD) $(LDFLAGS)

clean:
	rm -f $(OBJSG) $(OBJSN) $(OBJSD) $(EXECG) $(EXECN) $(EXECD)

runG: $(EXECG)
	./$(EXECG) $(ARGS)

runN: $(EXECN)
	./$(EXECN) $(ARGS)

runD: $(EXECD)
	./$(EXECD)

valgrind: $(EXECG)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXECG)