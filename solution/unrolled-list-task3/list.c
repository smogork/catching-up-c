#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

unrolled_ordered_list_t* ordered_list_create()
{
	unrolled_ordered_list_t* res = malloc(sizeof(unrolled_ordered_list_t));
	if (!res)
		return NULL;
	res->root = NULL;
	
	return res;
}

void ordered_list_destroy(unrolled_ordered_list_t* list)
{
	unrolled_list_node_t* cur = list->root;
	while (cur) {
		unrolled_list_node_t* next = cur->next;
		free(cur);
		cur = next;
	}
	free(list);
}

int ordered_list_insert_value(unrolled_ordered_list_t* list, int value)
{
	// Empty root case
	if (!list->root)
	{
		list->root = malloc(sizeof(unrolled_list_node_t));
		list->root->next = NULL;
		list->root->size = 1;
		list->root->values[0] = value;
		return 0;
	}

	unrolled_list_node_t** cur = &list->root;
	unrolled_list_node_t* prev = NULL;

	while (*cur && (*cur)->values[(*cur)->size - 1] < value) {
		prev = *cur;
		cur = &(*cur)->next;
	}

	// Previous node still has a space
	if (prev && prev->size < NODE_CAPACITY)
	{
		prev->values[prev->size] = value;
		prev->size++;
		return 0;
	}

	// This is insertion at the end of the list and previous is out of space
	if (*cur == NULL)
	{
		*cur = malloc(sizeof(unrolled_list_node_t));
		(*cur)->next = NULL;
		(*cur)->size = 1;
		(*cur)->values[0] = value;

		return 0;
	}

	// Previous and current node are full => split cur at half
	if ((*cur)->size == NODE_CAPACITY) {
		unrolled_list_node_t* split = malloc(sizeof(unrolled_list_node_t));
		split->next = (*cur)->next;
		split->size = NODE_CAPACITY / 2;
		split->values[0] = value;

		(*cur)->next = split;
		(*cur)->size = NODE_CAPACITY / 2;

		// Write the second half to the new node
		for (int i = 0; i < NODE_CAPACITY / 2; ++i)
			split->values[i] = (*cur)->values[NODE_CAPACITY / 2 + i];
	}

	// Find a place to insert a new value in cur
	int insert_idx = 0;
	for (; insert_idx < (*cur)->size; ++insert_idx)
		if ((*cur)->values[insert_idx] >= value)
			break;

	// Write old value one index right
	for (int i = (*cur)->size - 1; i >= insert_idx; --i)
		(*cur)->values[i + 1] = (*cur)->values[i];

	// Insert a value at selected place
	(*cur)->values[insert_idx] = value;
	(*cur)->size++;
	return 0;
}

int ordered_list_remove_value(unrolled_ordered_list_t* list, int value)
{
	// Empty root case
	if (!list->root)
		return 1;

	unrolled_list_node_t** cur = &list->root;
	unrolled_list_node_t* prev = NULL;

	while (*cur && (*cur)->values[(*cur)->size - 1] < value) {
		prev = *cur;
		cur = &(*cur)->next;
	}

	if (*cur == NULL)
		return 1;

	// Find a place to remove existing value in cur
	int remove_idx = 0;
	for (; remove_idx < (*cur)->size; ++remove_idx)
		if ((*cur)->values[remove_idx] == value)
			break;

	if (remove_idx == (*cur)->size)
		return 1;

	for (int i = remove_idx; i < (*cur)->size - 1; ++i)
		(*cur)->values[i] = (*cur)->values[i + 1];
	(*cur)->size--;

	if ((*cur)->size == 0)
	{
		unrolled_list_node_t* to_delete = *cur;
		if (NULL == prev)
			list->root = (*cur)->next;
		else
			prev->next = (*cur)->next;
		free(to_delete); // cannot use *cur, because we are going to modify `prev->next` which is the same as *cur.
	}
}

int ordered_list_print(unrolled_ordered_list_t* list)
{
	unrolled_list_node_t* node = list->root;

	while (node)
	{
		for (int i = 0; i < node->size; ++i)
			printf("%d ", node->values[i]);
		node = node->next;
	}
	printf("\n");
}
