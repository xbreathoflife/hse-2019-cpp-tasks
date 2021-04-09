#include "str.h"

char *my_strcpy(char * restrict s1, const char * restrict s2) {
    char *ptr = s1;

    while ((*s1++ = *s2++) != '\0') {
	}
    return ptr;
}

char *my_strcat(char * restrict s1, const char * restrict s2) {
    char *ptr = s1;

    while (*s1 != '\0')
		s1++;
	while ((*s1++ = *s2++) != '\0') {
	}

    return ptr;
}

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 == *s2 && *s1 != '\0') {
        s1++;
		s2++;
    }
    return (int)*s1 - (int)*s2;
}

size_t my_strlen(const char *s) {
    size_t len = 0;

    while (*s++ != '\0')
        len++;

    return len;
}
