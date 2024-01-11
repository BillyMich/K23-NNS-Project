#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <dirent.h>
#include "../include/Graph.h"
#include "../include/FindAllRightNeighborsAlgorithm.h"
#include "../include/knn.h"
#include "../include/knn_improvments.h"

int processFile(const char* filename, Graph* rightGraphResults) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open the file.");
        return 1;
    }
    char line[100];
    int neighbor;
    int points [10000][100]  ;
    int i = -1;
    int j=0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Node:", 5) == 0) {
            printf("Node: %d\n", i);
            i++;
            j=-1;
        } else if (strncmp(line, "Neighbor:", 9) == 0) {
            sscanf(line, "Neighbor: %d", &neighbor);
            points[i][j++] =neighbor;        
            }
    }
    fclose(file);

    Node * tempNodeRight = rightGraphResults->nodes;
    double count = 0 ;
    double correct = 0;
    j=0;

    while (tempNodeRight != NULL)
    {
        NodeNeighborsLinkedList * tempNodeListRight = tempNodeRight->neighbors;
        while (tempNodeListRight !=NULL)
        {
            count++;
            for (int  i = 0; i < 100; i++)
            {
                if (tempNodeListRight->node->nodeNameInt == points[j][i])
                {   
                    correct++;
                    break;
                }
                tempNodeListRight = tempNodeListRight->next;            
            }
            tempNodeListRight = tempNodeRight->neighbors;
            
        }
        j++;
        tempNodeRight = tempNodeRight->next;
    }
    
    printf("This is the accuartion %f /n",(correct / count )* 100);
    return 0;
}

int main() {
    printf("Starting...\n");
    Graph* graphRightResults = createGraphFromBinaryFile("../datasets/1000000.bin", 100);
    FindAllRightNeighbors(graphRightResults, "euclidean", 100);
    const char *directoryPath = "."; 
    DIR *dir;
    struct dirent *ent;
    while (1) { 
        if ((dir = opendir(directoryPath)) != NULL) {
            while ((ent = readdir(dir)) != NULL) {
                    processFile(ent->d_name,graphRightResults);
                    remove(ent->d_name);                 
            }
            closedir(dir);
        } else {
            perror("Unable to read directory");
            return 1;
        }
        sleep(10);
    }

    return 0;
}
