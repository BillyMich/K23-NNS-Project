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

void testEuclideanDistance2() {
    Dimension *dimension1 = NULL;
    addDimension(&dimension1, 1, 30.0);

    Dimension *dimension2 = NULL;
    addDimension(&dimension2, 1, 10.0);

    double cost = euclidean_distance(dimension1, dimension2);

    TEST_ASSERT(cost == 20.0);

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

void testManhattanDistance2() {
    Dimension *dimension1 = NULL;
    addDimension(&dimension1, 1, 5.0);

    Dimension *dimension2 = NULL;
    addDimension(&dimension2, 1, 15.0);

    double cost = manhattan_distance(dimension1, dimension2);

    TEST_ASSERT(cost == 10.0);

    freeDimensions(dimension1);
    freeDimensions(dimension2);
}

TEST_LIST = {
    {"testEuclideanDistance", testEuclideanDistance},
    {"testEuclideanDistance2", testEuclideanDistance2},
    {"testManhattanDistance", testManhattanDistance},
    {"testManhattanDistance2", testManhattanDistance2},
    {NULL, NULL}
};
