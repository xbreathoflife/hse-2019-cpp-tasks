#include <stdio.h>
#include <stdlib.h>

#include "point_list.h"

void add_point(struct intrusive_list *list, int x, int y) {
	struct point *p = malloc(sizeof(struct point));
	if (p == NULL)
		return;
	p->x = x;
	p->y = y;
	add_node(list, &p->node);
}

void remove_point(struct intrusive_list *list, int x, int y) { // removes all (x, y) pairs
	for (struct intrusive_node *element = list->head; element != NULL;) {
		struct point *p = container_of(element, struct point, node); 
		if (p->x == x && p->y == y) {
			element = element->next;
			remove_node(list, &p->node);
			free(p);
		}
		else
			element = element->next;
	}
}

void show_all_points(struct intrusive_list *list) {
	for (struct intrusive_node *element = list->head; element != NULL; element = element->next) {
		struct point *p = container_of(element, struct point, node); 
		printf("(%d %d) ", p->x, p->y);	
	}
	printf("\n");
}

void remove_all_points(struct intrusive_list *list) {
	for (struct intrusive_node *element = list->head; element != NULL;) {
		struct point *p = container_of(element, struct point, node); 
		element = element->next;
		remove_node(list, &p->node);
		free(p);
	}	
}

