#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "primitives.h"

void setUp(void) {
    srand(10);
}

void tearDown(void) {
    // clean stuff up here
}

void test_rand_int(void) {
    for (int i = 0; i < 10; ++i)
        TEST_ASSERT_EQUAL_MESSAGE(-1, rand_int(-1, 0), "Expected exclusive upper bound");

    const int lower_bound = -10;
    const int upper_bound = 10;
    for (int i = 0; i < 100; ++i)
    {
        int val = rand_int(lower_bound, upper_bound);
        TEST_ASSERT_LESS_OR_EQUAL_MESSAGE(upper_bound, val, "Expected exclusive upper bound");
        TEST_ASSERT_NOT_EQUAL_MESSAGE(upper_bound, val, "Expected exclusive upper bound");
        TEST_ASSERT_GREATER_OR_EQUAL_MESSAGE(lower_bound, val, "Expected inclusive lower bound");
    }
}

void test_rand_float(void) {
    const float lower_bound = -1.0;
    const float upper_bound = 1.0;
    for (int i = 0; i < 1000; ++i)
    {
        float val = rand_float(lower_bound, upper_bound);
        TEST_ASSERT_LESS_OR_EQUAL_FLOAT_MESSAGE(upper_bound, val, "Expected exclusive upper bound");
        TEST_ASSERT_NOT_EQUAL_FLOAT_MESSAGE(upper_bound, val, "Expected exclusive upper bound");
        TEST_ASSERT_GREATER_OR_EQUAL_FLOAT_MESSAGE(lower_bound, val, "Expected inclusive lower bound");
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_rand_int);
    RUN_TEST(test_rand_float);
    return UNITY_END();
}