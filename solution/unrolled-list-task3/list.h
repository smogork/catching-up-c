#pragma once

#define NODE_CAPACITY 4

typedef struct unrolled_list_node {
	int values[NODE_CAPACITY];
	int size;
	struct unrolled_list_node* next;
} unrolled_list_node_t;

typedef struct unrolled_ordered_list {
	unrolled_list_node_t* root;
} unrolled_ordered_list_t;

/// @brief 
/// This funkction creates an empty ordered list.
/// To release resources from this list properly, use ordered_list_destroy function.
/// @return Returns a pointer to the orderder list. Structure is already initialized.
unrolled_ordered_list_t* ordered_list_create();

/// @brief 
/// This function releases resources used by passed ordered list.
/// Using a list after cleaning it is undefined behaviour.
/// @param list Pointer to a valid list which will be cleaned (including all its nodes).
void ordered_list_destroy(unrolled_ordered_list_t* list);

/// @brief 
/// This function insterts a value into the list.
/// Operation doesn't violate ordering of data.
/// Operation can allocate new memory.
/// @param list Pointer to a list where data will be inserted.
/// @param value Value to insert
/// @return It should return 0 when succeeded. 1 Otherwise.
int ordered_list_insert_value(unrolled_ordered_list_t* list, int value);

/// @brief 
/// This function removes a given value from the list (when data is not unique, only one instance will be deleted).
/// Operation doesn't violate ordering of data.
// Allocation can release memory (and should).
/// @param list Pointer to a list from which data will be deleted
/// @param value Value to remove.
/// @return It should return 0 when removal finished succesfully. 1 Otherwise.
int ordered_list_remove_value(unrolled_ordered_list_t* list, int value);

/// @brief 
/// This functions prints the list content to the standard output.
/// @param list Pointer to list being printed out.
void ordered_list_print(unrolled_ordered_list_t* list);