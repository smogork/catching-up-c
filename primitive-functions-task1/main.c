#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "primitives.h"
#include "pointers.h"

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


void test_rand_byte(void) {
    rand_byte(); // Nothing can be checked here. Function has to be defined.
}

void test_rand_character(void) {
    char lower_bound = 0x20;
    char upper_bound = 0x7E;
    for (int i = 0; i < 1000; ++i)
    {
        char val = rand_character();
        TEST_ASSERT_LESS_OR_EQUAL_CHAR_MESSAGE(upper_bound, val, "Expected readable character");
        TEST_ASSERT_GREATER_OR_EQUAL_CHAR_MESSAGE(lower_bound, val, "Expected readable character");
    }
}

void test_add_integers(){
    // TODO: write a simple test
    TEST_IGNORE();
}

void test_add_integers2(){
    // TODO: write a simple test
    TEST_IGNORE();
}

void test_add_integers3(){
    // TODO: write a simple test
    TEST_IGNORE();
}

void test_add_integers4(){
    // TODO: write a simple test
    TEST_IGNORE();
}

void test_add_unsigned_overflow(){
    const unsigned int lhs = UINT32_MAX;
    const unsigned int rhs = 2;

    unsigned int res = add_unsigned(lhs, rhs);

    TEST_ASSERT_EQUAL_MESSAGE(1u, res, "Expected well defined overflow");
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_rand_int);
    RUN_TEST(test_rand_float);
    RUN_TEST(test_rand_byte);
    RUN_TEST(test_rand_character);
    RUN_TEST(test_add_integers);
    RUN_TEST(test_add_integers2);
    RUN_TEST(test_add_integers3);
    RUN_TEST(test_add_integers4);
    RUN_TEST(test_add_unsigned_overflow);
    return UNITY_END();
}