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
    
    TEST_ASSERT(dim->next == NULL);
    freeDimensions(dim);
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

    freeDimensions(head);
}

void testAddDimension2() {
    Dimension* head = NULL;
    addDimension(&head, 1, 10.0);
    addDimension(&head, 2, 20.0);
    addDimension(&head, 3, 30.0);

    TEST_ASSERT(head != NULL);  
    TEST_ASSERT(head->dimensionValue == 1);  
    TEST_ASSERT(head->value == 10.0);  
    TEST_ASSERT(head->next != NULL);  

    // Check the second dimension
     Dimension* second = head->next;
    TEST_ASSERT(second != NULL);
    TEST_ASSERT(second->dimensionValue == 2);
    TEST_ASSERT(second->value == 20.0);
    TEST_ASSERT(second->next != NULL);

    // Check the Third dimension
    Dimension* third = second->next;
    TEST_ASSERT(third != NULL);
    TEST_ASSERT(third->dimensionValue == 3);
    TEST_ASSERT(third->value == 30.0);
    TEST_ASSERT(third->next == NULL);

    freeDimensions(head);
}


void testAddDimension3() {
    Dimension* head = NULL;
    addDimension(&head, 1, 10.0);
    addDimension(&head, 2, 20.0);
    addDimension(&head, 3, 30.0);
    addDimension(&head, 4, 40.0);


    TEST_ASSERT(head != NULL);  
    TEST_ASSERT(head->dimensionValue == 1);  
    TEST_ASSERT(head->value == 10.0);  
    TEST_ASSERT(head->next != NULL);  

    // Check the second dimension
    Dimension* second = head->next;
    TEST_ASSERT(second != NULL);
    TEST_ASSERT(second->dimensionValue == 2);
    TEST_ASSERT(second->value == 20.0);
    TEST_ASSERT(second->next != NULL);

    // Check the Third dimension
    Dimension* third = second->next;
    TEST_ASSERT(third != NULL);
    TEST_ASSERT(third->dimensionValue == 3);
    TEST_ASSERT(third->value == 30.0);
    TEST_ASSERT(third->next != NULL);

    // Check the Forth dimension
    Dimension* forth = third->next;
    TEST_ASSERT(forth != NULL);
    TEST_ASSERT(forth->dimensionValue == 4);
    TEST_ASSERT(forth->value == 40.0);
    TEST_ASSERT(forth->next == NULL);

    freeDimensions(head);
}


void testDimension() {
    Dimension* headDimension = NULL;
    addDimension(&headDimension, 1, 1.2345);
    addDimension(&headDimension, 2, 2.3456);
    addDimension(&headDimension, 3, 3.4567);
    addDimension(&headDimension, 4, 4.5678);

    double expectedValues[] = {1.2345, 2.3456, 3.4567, 4.5678};
    
    Dimension* tempDimension = headDimension;
    int count = 0;

    while (tempDimension != NULL) {
        TEST_ASSERT(tempDimension->dimensionValue == count + 1); 
        TEST_ASSERT(tempDimension->value == expectedValues[count]);
        
        tempDimension = tempDimension->next;
        count++;
    }

    freeDimensions(headDimension);
}


TEST_LIST = {
    {"testInitDimension", testInitDimension},
    {"testAddDimension", testAddDimension},
    {"testAddDimension2", testAddDimension2},
    {"testAddDimension3", testAddDimension3},
    {"testDimensionAdd", testDimension},
    {NULL, NULL}
};
