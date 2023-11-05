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
    addDimension(&dimension1, 2, 20.0);

    Dimension *dimension2 = NULL;
    addDimension(&dimension2, 1, 5.0);
    addDimension(&dimension2, 2, 15.0);

    double cost = euclidean_distance(dimension1, dimension2);

    TEST_ASSERT(cost == 10.0);

    freeDimensions(dimension1);
    freeDimensions(dimension2);
}

void testManhattanDistance() {
    Dimension *dimension1 = NULL;
    addDimension(&dimension1, 1, 10.0);
    addDimension(&dimension1, 2, 20.0);

    Dimension *dimension2 = NULL;
    addDimension(&dimension2, 1, 5.0);
    addDimension(&dimension2, 2, 15.0);

    double cost = manhattan_distance(dimension1, dimension2);

    TEST_ASSERT(cost == 20.0);

    freeDimensions(dimension1);
    freeDimensions(dimension2);
}

TEST_LIST = {
    {"testEuclideanDistance", testEuclideanDistance},
    {"testManhattanDistance", testManhattanDistance},
    {NULL, NULL}
};
