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

void* int_to_string (void* el) {
	int i = *(int*)el;
	char* str = (char*)malloc(80);
	sprintf(str, "n. %d", i);
	return str;
}

void test_linked_list_map () {
	int i[] = { 6, 5, 3, 2, 1, 4 };

	// un filo scomodo costruire una lista di primitivi
	linked_list* ll = linked_list_create(&i[0]);
	linked_list_add(ll, &i[1]);
	linked_list_add(ll, &i[2]);
	linked_list_add(ll, &i[3]);
	linked_list_add(ll, &i[4]);
	linked_list_add(ll, &i[5]);

	linked_list* mapped = linked_list_map(ll, int_to_string);

	assertStrEquals("n. 6", (char*)linked_list_get(mapped, 0));
	assertStrEquals("n. 5", (char*)linked_list_get(mapped, 1));
	assertStrEquals("n. 3", (char*)linked_list_get(mapped, 2));
	assertStrEquals("n. 2", (char*)linked_list_get(mapped, 3));
	assertStrEquals("n. 1", (char*)linked_list_get(mapped, 4));
	assertStrEquals("n. 4", (char*)linked_list_get(mapped, 5));
}

void count_reduce (void* value, void* el) {
	int v = *(int*)value;
	*(int*)value = v + 1;
}

void sum_reduce (void* value, void* el) {
	int v = *(int*)value;
	*(int*)value = v + *(int*)el;
}

void test_linked_list_reduce () {
	int i[] = { 6, 5, 3, 2, 1, 4 };
	int count = 0;
	int sum = 0;

	// un filo scomodo costruire una lista di primitivi
	linked_list* ll = linked_list_create(&i[0]);
	linked_list_add(ll, &i[1]);
	linked_list_add(ll, &i[2]);
	linked_list_add(ll, &i[3]);
	linked_list_add(ll, &i[4]);
	linked_list_add(ll, &i[5]);

	linked_list_reduce(ll, &count, count_reduce);
	linked_list_reduce(ll, &sum, sum_reduce);

	assertEquals(6, count);
	assertEquals(21, sum);
}

typedef struct {
	char nome[20];
	int eta;
	float altezza;
} Persona;

boolean filter_enrico (void* persona) {
	Persona p = *(Persona*)persona;
	if (strcmp(p.nome, "Enrico") == 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

boolean filter_days (void* persona) {
	Persona p = *(Persona*)persona;
	if (p.eta < 19000) {
		return TRUE;
	} else {
		return FALSE;
	}
}

void* map_year_to_days (void *persona) {
	Persona p = *(Persona*)persona;
	Persona *p2 = (Persona*) malloc(sizeof(Persona));
	strcpy (p2->nome, p.nome);
	p2->eta = p.eta * 365;
	p2->altezza = p.altezza;
	return p2;
}

void sum_heights (void *value, void *persona) {
	float altezze = *(float*)value;
	Persona p = *(Persona*)persona;
	*(float*)value = (altezze + p.altezza);
}

void test_difficile () {
	// dato un elenco di persone, calcola l'altezza media delle persone di meno di che hanno vissuto almeno 3000 giorni che si chiamano enrico
	Persona persone[] = { { .nome = "Enrico", 		.eta = 34, .altezza = 1.78 },
						  { .nome = "Giovanni", 	.eta = 12, .altezza = 1.48 },
						  { .nome = "Francesca", 	.eta = 11, .altezza = 1.56 },
						  { .nome = "Luigi", 		.eta = 30, .altezza = 1.76 },
						  { .nome = "Enrico", 		.eta = 54, .altezza = 1.73 },
						  { .nome = "Enrico", 		.eta = 22, .altezza = 1.67 },
						  { .nome = "Matteo", 		.eta = 12, .altezza = 1.62 },
						  { .nome = "Luca", 		.eta = 84, .altezza = 1.89 },
						  { .nome = "Arnaldo", 		.eta = 23, .altezza = 1.55 },
						  { .nome = "Michele", 		.eta = 56, .altezza = 1.69 }
						};
	linked_list* ll = NULL;
	for (int i=0; i<(sizeof(persone) / sizeof(persone[0])); i++) {
		if (ll == NULL) {
			ll = linked_list_create(&persone[i]);
		} else {
			linked_list_add(ll, &persone[i]);
		}
	}
	int count = linked_list_size(ll);

	ll = linked_list_filter(ll, filter_enrico);
	count = linked_list_size(ll);

	ll = linked_list_map(ll, map_year_to_days);
	ll = linked_list_filter(ll, filter_days);

	float altezze = 0;
	linked_list_reduce(ll, &altezze, sum_heights);
	count = linked_list_size(ll);
	float mediaAltezze = 0.0;
	if (count > 0) {
		mediaAltezze = altezze / count;
	}

	printf ("Media Altezze delle persone che si chiamano enrico: %g\n", mediaAltezze);
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

	test_linked_list_map();

	test_linked_list_reduce ();

	test_difficile();

	print_test_results();
}

