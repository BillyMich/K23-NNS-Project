/////////////////////////////////////////////////////////////////
//
//
// Unit tests for math functions.
//
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"
#include "../include/MathematicalFunctions.h"
#include "../include/Dimension.h"
#include <math.h>
#include <string.h>

void testEuclideanDistance() {
    Dimension *dimension1 = NULL;
    addDimension(&dimension1, 1, 10.0);

    Dimension *dimension2 = NULL;
    addDimension(&dimension2, 1, 20.0);

    double cost = euclidean_distance(dimension1, dimension2);

    TEST_ASSERT(cost == 10.0);

    freeDimensions(dimension1);
    freeDimensions(dimension2);
}

void testManhattanDistance() {
    Dimension *dimension1 = NULL;
    addDimension(&dimension1, 1, 10.0);

    Dimension *dimension2 = NULL;
    addDimension(&dimension2, 1, 15.0);

    double cost = manhattan_distance(dimension1, dimension2);

    TEST_ASSERT(cost == 5.0);

    freeDimensions(dimension1);
    freeDimensions(dimension2);
}

void testDistanceFunc() {
    Dimension *dimension1 = NULL;
    addDimension(&dimension1, 1, 1.000);

    Dimension *dimension2 = NULL;
    addDimension(&dimension2, 1, 0.500);

    double cost = distance(dimension1, dimension2, "manhattan");
    TEST_ASSERT(cost == 0.5);

    cost = distance(dimension1, dimension2, "euclidean");
    TEST_ASSERT(cost == 0.5);

    freeDimensions(dimension1);
    freeDimensions(dimension2);
}

TEST_LIST = {
    {"testEuclideanDistance", testEuclideanDistance},
    {"testManhattanDistance", testManhattanDistance},
    {"testDistanceFunc", testDistanceFunc},
    {NULL, NULL}
};
