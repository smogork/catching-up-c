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

    for (int i = 10; i >= 0; --i)
        ordered_list_insert_value(list, i);
    ordered_list_print(list);

    ordered_list_destroy(list);
}

void test_ordered_list_remove_in_the_middle(void) {
    unrolled_ordered_list_t* list = ordered_list_create();

    for (int i = 10; i >= 0; --i)
        ordered_list_insert_value(list, i);

    ordered_list_remove_value(list, 6);
    ordered_list_remove_value(list, 7);
    ordered_list_remove_value(list, 8);
    ordered_list_remove_value(list, 9);

    ordered_list_print(list);
    ordered_list_destroy(list);
}

void test_ordered_list_remove_head(void) {
    unrolled_ordered_list_t* list = ordered_list_create();

    for (int i = 10; i >= 0; --i)
        ordered_list_insert_value(list, i);

    ordered_list_remove_value(list, 0);
    ordered_list_remove_value(list, 1);
    ordered_list_remove_value(list, 2);
    ordered_list_remove_value(list, 3);

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