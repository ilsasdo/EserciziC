#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "../src/linked_list.h"

void test_linked_list_create () {
	char* prova = "prova";
	linked_list* ll = linked_list_create(prova);
	assertNotNull(&ll);
	assertStrEquals((char*)ll->value, "prova");
}

void test_linked_list_size () {
	char* prova = "prova";
	linked_list* ll = linked_list_create(prova);
	assertEquals(1, linked_list_size(ll));
}

void test_linked_list_get_last () {
	char* prova = "prova";
	linked_list* ll = linked_list_create(prova);
	linked_list* last = linked_list_get_last(ll);
	assertStrEquals((char*)last->value, "prova");
	assertNull(last->next);
}

void test_linked_list_add () {
	char* prova = "prova";
	linked_list* ll = linked_list_create(prova);

	char* test = "test";
	linked_list_add(ll, test);

	assertEquals(2, linked_list_size(ll));
	assertStrEquals("test", (char*)(linked_list_get_last(ll)->value));
}

boolean filterLessThan3 (void* value) {
	int i = *(int*)value;
	if (i < 3) {
		return TRUE;
	} else {
		return FALSE;
	}
}

void test_linked_list_filter () {
	int i[] = { 1, 2, 3, 4, 5, 6 };

	// un filo scomodo costruire una lista di primitivi
	linked_list* ll = linked_list_create(&i[0]);
	linked_list_add(ll, &i[1]);
	linked_list_add(ll, &i[2]);
	linked_list_add(ll, &i[3]);
	linked_list_add(ll, &i[4]);
	linked_list_add(ll, &i[5]);

	ll = linked_list_filter(ll, filterLessThan3);
	assertEquals(2, linked_list_size(ll));

	// un filo scomodo accedere ai valori nella lista...
	assertEquals(2, *((int*)(linked_list_get_last(ll)->value)));
}

void test_linked_list_get () {
	int i[] = { 1, 2, 3, 4, 5, 6 };

	// un filo scomodo costruire una lista di primitivi
	linked_list* ll = linked_list_create(&i[0]);
	linked_list_add(ll, &i[1]);
	linked_list_add(ll, &i[2]);
	linked_list_add(ll, &i[3]);
	linked_list_add(ll, &i[4]);
	linked_list_add(ll, &i[5]);

	int q = *(int*)linked_list_get(ll, 3);
	assertEquals(4, q);
}

int compare_int (void* el1, void* el2) {
	int a = *(int*)el1;
	int b = *(int*)el2;

	if (a > b) {
		return +1;
	}

	if (a < b) {
		return -1;
	}

	return 0;
}

void test_linked_list_sort_asc () {
	int i[] = { 6, 5, 3, 2, 1, 4 };

	// un filo scomodo costruire una lista di primitivi
	linked_list* ll = linked_list_create(&i[0]);
	linked_list_add(ll, &i[1]);
	linked_list_add(ll, &i[2]);
	linked_list_add(ll, &i[3]);
	linked_list_add(ll, &i[4]);
	linked_list_add(ll, &i[5]);

	linked_list_sort_asc(&ll, compare_int);

	assertEquals(1, *(int*)linked_list_get(ll, 0));
	assertEquals(2, *(int*)linked_list_get(ll, 1));
	assertEquals(3, *(int*)linked_list_get(ll, 2));
	assertEquals(4, *(int*)linked_list_get(ll, 3));
	assertEquals(5, *(int*)linked_list_get(ll, 4));
	assertEquals(6, *(int*)linked_list_get(ll, 5));
}

void test_linked_list_sort_desc () {
	int i[] = { 6, 5, 3, 2, 1, 4 };

	// un filo scomodo costruire una lista di primitivi
	linked_list* ll = linked_list_create(&i[0]);
	linked_list_add(ll, &i[1]);
	linked_list_add(ll, &i[2]);
	linked_list_add(ll, &i[3]);
	linked_list_add(ll, &i[4]);
	linked_list_add(ll, &i[5]);

	linked_list_sort_desc(&ll, compare_int);

	assertEquals(6, *(int*)linked_list_get(ll, 0));
	assertEquals(5, *(int*)linked_list_get(ll, 1));
	assertEquals(4, *(int*)linked_list_get(ll, 2));
	assertEquals(3, *(int*)linked_list_get(ll, 3));
	assertEquals(2, *(int*)linked_list_get(ll, 4));
	assertEquals(1, *(int*)linked_list_get(ll, 5));
}

int main(int argc, char *argv[]) {
	test_linked_list_create();

	test_linked_list_size();

	test_linked_list_get_last();

	test_linked_list_add();

	test_linked_list_filter();

	test_linked_list_get();

	test_linked_list_sort_asc();

	test_linked_list_sort_desc();

	print_test_results();
}

