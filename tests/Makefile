# paths
INCLUDE = ../include
MODULES = ../modules
DATASETS = ../datasets

# compiler
CC = gcc

CFLAGS = -Wall -Werror -g -I$(INCLUDE)
LDFLAGS = -lm

# .o files
OBJS = graph_test.o $(MODULES)/Graph.o

# Executable
EXEC = graph_test

ARGS = 

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)
