#include "gtest/gtest.h"
#include "OrdenamientoHierarchy.cc"

#include <iostream>
#include <vector>

using namespace std;

template<class instanceType>
class FixTyped : public testing::Test
{
public:
    FixTyped()
    {
        instance2Test = new instanceType;
    }
    ~FixTyped()
    { 
        delete instance2Test;
        instance2Test = NULL;
    }
protected:
    Base <int> * instance2Test;
};

typedef testing::Types< Ordenamiento <int> > implementations;

TYPED_TEST_CASE(FixTyped, implementations);

TYPED_TEST(FixTyped, testName)
{
    int values[5] = {3, 1, 5, 9, 7};;

    this->instance2Test->burbuja(values, 5, this->instance2Test->desc);
    
    for (int a = 0; a < 4; a++){
        EXPECT_GE(values[a], values[a+1]);
    }
}