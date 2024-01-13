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
    int points [200][20];
    int i = -1;
    int j=0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Node:", 5) == 0) {
            i++;
            j=0;
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
                    count+=20;
        while (tempNodeListRight !=NULL)
        {
            for (int  i = 0; i < 20; i++)
            {
                if (tempNodeListRight->node->nodeNameInt == points[j][i])
                {   
                    correct++;
                }
            }

            tempNodeListRight = tempNodeListRight->next;
        }
        j++;
        tempNodeRight = tempNodeRight->next;
    }
    
    printf("%f , %f \n",correct , count);
    printf("This is the accuartion %f /n",(correct / count )* 100);

    file = fopen("example.txt", "a");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; // Exit with an error code
    }

    // Write a line to the file
    fprintf(file, " %f\n",(correct/count)*100);

    // Close the file
    fclose(file);
    return 0;
}

int main() {
    Graph* graphRightResults = createGraphFromBinaryFile("../datasets/asciiData3.bin", 5);
    FindAllRightNeighbors(graphRightResults, "improved", 20);
    const char *directoryPath = "./txtfiles"; 
    DIR *dir;
    struct dirent *ent;

    while (1) { 
        if ((dir = opendir(directoryPath)) != NULL) {
            while ((ent = readdir(dir)) != NULL) {
                    printf("%s\n",ent->d_name);
                    if (!(strcmp(ent->d_name, ".")==0) &&  !(strcmp(ent->d_name, "..")==0))
                    {
                    printf( "%s\n", ent->d_name);
                    char originalStr[] = "./txtfiles";  // Original string
                    char newStr[500];
                    sprintf(newStr, "%s/%s", originalStr, ent->d_name);
                    printf("%s\n",newStr);
                    processFile(newStr,graphRightResults);
                    }//remove(newStr);                 
            }
            closedir(dir);
        } else {
            perror("Unable to read directory");
            return 1;
        }
        printf("Sleeping for 10 seconds...\n");
        sleep(10);
    }

    return 0;
}
