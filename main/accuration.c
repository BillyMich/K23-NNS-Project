#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <dirent.h>
#include "../include/Graph.h"
#include "../include/FindAllRightNeighborsAlgorithm.h"
#include "../include/knn.h"
#include "../include/knn_improvments.h"

int processFile(const char* filename, Graph* rightGraphResults, int geitones , int K) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open the file.");
        return 1;
    }
    char line[100];
    int neighbor;
    int points [K][geitones];
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
        count+=geitones;
        while (tempNodeListRight !=NULL)
        {
            for (int  i = 0; i < geitones; i++)
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
    fprintf(file, "accuration:%f-%s\n",(correct/count)*100,filename);

    // Close the file
    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {

    int geitones = atoi(argv[1]);
    int K = atoi(argv[2]);
    int dimension = atoi(argv[3]);

    Graph* graphRightResults = createGraphFromBinaryFile(argv[4], dimension);
    FindAllRightNeighbors(graphRightResults, "improved", geitones);
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
                    processFile(newStr,graphRightResults,geitones,K);
                    remove(newStr);
                    }                 
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
