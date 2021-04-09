#include <stdio.h>

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

void reverse_node(struct intrusive_list *list) {
	struct intrusive_node *cur_node = list->head, *next_node, *prev_node = NULL;

	while (cur_node) {
		next_node = cur_node->next;
		cur_node->next = prev_node;
		cur_node->prev = next_node;
		prev_node = cur_node;
		cur_node = next_node;
	}
	list->head = prev_node;
}

void apply(struct intrusive_list *list, void (*op)(struct intrusive_node *node, void *data), void *data) {
	void (*func)(struct intrusive_node *, void *);
	func = op;
	for (struct intrusive_node *element = list->head; element != NULL; element = element->next) {
		func(element, data);
	}
}
