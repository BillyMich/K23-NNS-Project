#ifndef MATHEMATICAL_FUNCTIONS_H
#define MATHEMATICAL_FUNCTIONS_H

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "Node.h"
#include "common_types.h"
#include <string.h>

double euclidean_distance(Dimension* nodeDimension1 , Dimension* nodeDimension2);

double manhattan_distance(Dimension* nodeDimension1 , Dimension* nodeDimension2);

double calculate_norm(Dimension* head);

double euclidean_distance_improved(Node* node1, Node* node2);

double distance(Node* node1, Node* node2, String distance_function);

#endif 