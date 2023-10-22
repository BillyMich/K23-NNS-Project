#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"

typedef struct Dimension Dimension;

struct Dimension{
    int level; 
    double value;
    Dimension* nextDimension; //ERROR: unknown type name ‘Dimension’ - same below
};