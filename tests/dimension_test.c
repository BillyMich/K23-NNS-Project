/////////////////////////////////////////////////////////////////
//
//
// Unit tests for Dimensions.
// 
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"	
#include "Dimension.h"

void testInitDimension() {
    Dimension* dim = initDimension();
    TEST_ASSERT(dim != NULL); 
    TEST_ASSERT(dim->dimensionValue == 0);  
    TEST_ASSERT(dim->value == 0.0);  
    TEST_ASSERT(dim->next == NULL);
    freeDimension(dim);
}

void testAddDimension() {
    Dimension* head = NULL;
    addDimension(&head, 1, 10.0);
    addDimension(&head, 2, 20.0);

    TEST_ASSERT(head != NULL);  
    TEST_ASSERT(head->dimensionValue == 1);  
    TEST_ASSERT(head->value == 10.0);  
    TEST_ASSERT(head->next != NULL);  
    
    // Check the second dimension
    Dimension* second = head->next;
    TEST_ASSERT(second != NULL);
    TEST_ASSERT(second->dimensionValue == 2);
    TEST_ASSERT(second->value == 20.0);
    TEST_ASSERT(second->next == NULL);

    freeDimension(head);
}

TEST_LIST = {
    {"testInitDimension", testInitDimension},
    {"testAddDimension", testAddDimension},
    {NULL, NULL}
};
