#include <assert.h>
#include "str.h"
#include "test_str.h"

void test_strcpy(void) {
	char s1[30];
	char s2[30] = "";
	char s3[30] = "CPP will rock you";
	
	my_strcpy(s1, s2);
	assert(*s1 == '\0');
	my_strcpy(s1, s3);
	assert(!my_strcmp(s1, s3));
}

void test_strcat(void) {
	char s1[50] = "It's where my ";
	char s2[50] = "demons hide";
	char s3[50] = "natural a beating ";
	char s4[50] = "heart of stone";

	my_strcat(s1, s2);
	assert(!my_strcmp(s1, "It's where my demons hide"));
	my_strcat(s3, s4);
	assert(!my_strcmp(s3, "natural a beating heart of stone"));
}


void test_strcmp(void) {
	char s1[50] = "Hello it's me";
	char s2[50] = "Hell";

	assert(my_strcmp(s1, s2) > 0);
	assert(my_strcmp(s1, s1) == 0);
	assert(my_strcmp(s2, s1) < 0);
}


void test_strlen(void) {
	char s1[30] = "";
	char s2[30] = "Believer";
	char s3[30] = "A believer";

	assert(my_strlen(s1) == 0);
	assert(my_strlen(s2) == 8);
	assert(my_strlen(s3) == 10);
}


