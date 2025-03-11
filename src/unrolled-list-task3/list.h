#pragma once

#define NODE_CAPACITY 4

typedef struct unrolled_list_node {
	/* Define me*/
} unrolled_list_node_t;

typedef struct unrolled_ordered_list {
	/* Define me */
} unrolled_ordered_list_t;

unrolled_ordered_list_t* ordered_list_create();
void ordered_list_destroy(unrolled_ordered_list_t* list);

int ordered_list_insert_value(unrolled_ordered_list_t* list, int value);
int ordered_list_remove_value(unrolled_ordered_list_t* list, int value);
int ordered_list_print(unrolled_ordered_list_t* list);