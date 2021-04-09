#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "point_list.h"

/* print points (stdout) */
void print(struct intrusive_node *node, void *data) {
	struct point *p = container_of(node, struct point, node);
	printf((const char *)data, p->x, p->y);
}

/* count the number of points */
void count(struct intrusive_node *node, void *data) {
	(void) node;	
	(*(int *)data)++;
}

/* save points to txt file */
void print_text(struct intrusive_node *node, void *data) {
	struct point *p = container_of(node, struct point, node);
	fprintf((FILE *)data, "%d %d\n", p->x, p->y);
}

/* save points to binary file */
void print_bin(struct intrusive_node *node, void *data) {
	struct point *p = container_of(node, struct point, node);
	fwrite(&p->x, 3, 1, (FILE *)data);
	fwrite(&p->y, 3, 1, (FILE *)data);
}

int main(int argc, char *argv[]) {
	int x, y;
	(void) argc;
	struct intrusive_list l;
	init_list(&l);

	if (strcmp(argv[1], "loadtext") == 0) {				// load points from txt file 
		FILE *fin = fopen(argv[2], "r");
		assert(fin != NULL);

		while (fscanf(fin, "%d %d", &x, &y) != EOF) {
			add_point(&l, x, y);
		}
		reverse_node(&l);
		fclose(fin);
	} else {
		FILE *fin = fopen(argv[2], "rb");				// load points from binary file
		assert(fin != NULL);
		unsigned char buffer[6];
		int x, y;
			while (!feof(fin)) {
				if (!fread(buffer, 1, 6, fin))
					break;
				if ((buffer[2] & (1 << 7)) == 0) {
					x = (((buffer[2] << 8) | buffer[1]) << 8) | buffer[0];
				} else {
					buffer[2] = ~buffer[2];
					buffer[1] = ~buffer[1];
					buffer[0] = ~buffer[0] + 1;
					x = -1 * ((((buffer[2] << 8) | buffer[1]) << 8) | buffer[0]);
				}
				if ((buffer[5] & (1 << 7)) == 0) {
					y = (((buffer[5] << 8) | buffer[4]) << 8) | buffer[3];
				} else {
					buffer[5] = ~buffer[5];
					buffer[4] = ~buffer[4];
					buffer[3] = ~buffer[3] + 1;
					y = -1 * ((((buffer[5] << 8) | buffer[4]) << 8) | buffer[3]);
				}				
				add_point(&l, x, y);
			}		
		reverse_node(&l);
		fclose(fin);		
	}
	if (strcmp(argv[3], "count") == 0) {									// count the number of points
		int cnt = 0;
		apply(&l, count, &cnt);
		printf("%d\n", cnt);
	} else if (strcmp(argv[3], "print") == 0) {			// print points (stdout)
		apply(&l, print, argv[4]);
		printf("\n");
	} else if (strcmp(argv[3], "savetext") == 0) {	// save points to txt file
		FILE *fout = fopen(argv[4], "w");
		apply(&l, print_text, fout);
		fclose(fout);
	} else {										// save points to binary file
		FILE *fout = fopen(argv[4], "wb");
		apply(&l, print_bin, fout);
		fclose(fout);
	}

	remove_all_points(&l);
	return 0;
}
