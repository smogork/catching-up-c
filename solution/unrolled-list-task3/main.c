#include "unity.h"
#include "list.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_ordered_list_insertion(void) {
    unrolled_ordered_list_t* list = ordered_list_create();
    TEST_ASSERT_NOT_EQUAL_MESSAGE(NULL, list, "Expected successful list creation");

    for (int i = 10; i >= 0; --i)
        TEST_ASSERT_EQUAL_MESSAGE(0, ordered_list_insert_value(list, i),  "Expected successfull insertion");
    ordered_list_print(list);

    ordered_list_destroy(list);
}

void test_ordered_list_remove_in_the_middle(void) {
    unrolled_ordered_list_t* list = ordered_list_create();
    TEST_ASSERT_NOT_EQUAL_MESSAGE(NULL, list, "Expected successful list creation");

    for (int i = 10; i >= 0; --i)
        TEST_ASSERT_EQUAL_MESSAGE(0, ordered_list_insert_value(list, i), "Expected successfull insertion");

    TEST_ASSERT_EQUAL_MESSAGE(0, ordered_list_remove_value(list, 7), "Expected successfull removal");
    TEST_ASSERT_EQUAL_MESSAGE(0, ordered_list_remove_value(list, 8), "Expected successfull removal");
    TEST_ASSERT_EQUAL_MESSAGE(0, ordered_list_remove_value(list, 9), "Expected successfull removal");
    TEST_ASSERT_EQUAL_MESSAGE(0, ordered_list_remove_value(list, 6), "Expected successfull removal");
    TEST_ASSERT_EQUAL_MESSAGE(1, ordered_list_remove_value(list, 6), "Expected unsuccessfull removal");

    ordered_list_print(list);
    ordered_list_destroy(list);
}

void test_ordered_list_remove_head(void) {
    unrolled_ordered_list_t* list = ordered_list_create();
    TEST_ASSERT_NOT_EQUAL_MESSAGE(NULL, list, "Expected successful list creation");

    for (int i = 10; i >= 0; --i)
        TEST_ASSERT_EQUAL_MESSAGE(0, ordered_list_insert_value(list, i),  "Expected successfull insertion");

    TEST_ASSERT_EQUAL_MESSAGE(0, ordered_list_remove_value(list, 0), "Expected successfull removal");
    TEST_ASSERT_EQUAL_MESSAGE(0, ordered_list_remove_value(list, 1), "Expected successfull removal");
    TEST_ASSERT_EQUAL_MESSAGE(0, ordered_list_remove_value(list, 2), "Expected successfull removal");
    TEST_ASSERT_EQUAL_MESSAGE(0, ordered_list_remove_value(list, 3), "Expected successfull removal");
    TEST_ASSERT_EQUAL_MESSAGE(1, ordered_list_remove_value(list, 3), "Expected unsuccessfull removal");

    ordered_list_print(list);
    ordered_list_destroy(list);
}


// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_ordered_list_insertion);
    RUN_TEST(test_ordered_list_remove_in_the_middle);
    RUN_TEST(test_ordered_list_remove_head);
    return UNITY_END();
}