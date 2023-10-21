#include <stdio.h>
#include <stdlib.h>

FILE* readFile(char *filename) {
    return fopen(filename, "r");
}