#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "clist.h"

struct point {
	int x, y;
	struct intrusive_node node;
};

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

int main() {
	char str[31] = "";
	int x, y;
	struct intrusive_list l;
	init_list(&l);

	while (strcmp(str, "exit")) {
		scanf("%30s", str);
		if (strcmp(str, "add") == 0) {
			scanf("%d %d", &x, &y);
			add_point(&l, x, y);		
		} else if (strcmp(str, "rm") == 0) {
			scanf("%d %d", &x, &y);
			remove_point(&l, x, y);
		} else if (strcmp(str, "print") == 0) {
			show_all_points(&l);
		} else if (strcmp(str, "rma") == 0) {
			remove_all_points(&l);
		} else if (strcmp(str, "len") == 0) {
			printf("%d\n", get_length(&l));
		} else if (strcmp(str, "exit") == 0) {
	
		} else {
			printf("Unknown command\n");
		}

	}
	if (get_length(&l) != 0)
		remove_all_points(&l);
	return 0;
}
