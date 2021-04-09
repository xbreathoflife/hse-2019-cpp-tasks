#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mergesort.h"

void copy(void *dest, void *src, size_t element_size) {
	char *ch_dest = dest;
	char *ch_src = src;
	size_t i;

	for (i = 0; i < element_size; i++) {
		ch_dest[i] = ch_src[i];	
	}
}

void merge(void *array, size_t m, size_t elements, size_t element_size, int (*comparator)(const void*, const void*)) {
	void *result = malloc(elements * sizeof(element_size));
	assert(result != NULL);
	size_t index_a = 0, index_b = m, index_res = 0;
	char *src = array, *r = result;

	for (index_res = 0; index_res < elements; index_res++) {
		if ((index_b >= elements) || (index_a < m && (*comparator)(src + index_a * element_size, src + index_b * element_size) < 0)) {
			copy(r + index_res * element_size, src + index_a * element_size, element_size);
			index_a++;
		} else {
			copy(r + index_res * element_size, src + index_b * element_size, element_size);
			index_b++;
		}	
	}
	copy(src, r, element_size * elements);
	free(result);
}  

void mergesort(void *array, size_t elements, size_t element_size, int (*comparator)(const void*, const void*)) {
	size_t m;
	char *p = array;

	if (elements < 2)
		return;

	m = elements / 2;
	mergesort(p, m, element_size, comparator);
	mergesort(p + m * element_size, elements - m, element_size, comparator);
	merge(array, m, elements, element_size, comparator);  
}
