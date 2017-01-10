#include "first.h"
#include "gtest/gtest.h"

TEST(Factorial, positivos){
	ASSERT_EQ(1, factorial(1));
	ASSERT_EQ(120, factorial(5));
}

TEST(Factorial, cero){
	ASSERT_EQ(1, factorial(0));

}

TEST(Factorial, negativos){
	ASSERT_EQ(0, factorial(-2));
	ASSERT_EQ(0, factorial(-1));

}