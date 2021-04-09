#include <stdlib.h>
#include "clist.h"

void init_list(struct intrusive_list *list) {
	list->head = NULL;
}

void add_node(struct intrusive_list *list, struct intrusive_node *node) {
	node->next = list->head;
	node->prev = NULL;

	if (list->head != NULL)
		list->head->prev = node;

	list->head = node;
}

void remove_node(struct intrusive_list *list, struct intrusive_node *node) {
	if (node == list->head) {
		list->head = node->next;
		if (list->head != NULL)
			list->head->prev = NULL;
	} else {
		node->prev->next = node->next;
		if (node->next != NULL)
			node->next->prev = node->prev;
	}
}

int get_length(struct intrusive_list *list) {
	int cnt = 0;
	struct intrusive_node *ptr = list->head;
	
	while (ptr != NULL) {
		ptr = ptr->next;
		cnt++;	
	}

	return cnt;
}
