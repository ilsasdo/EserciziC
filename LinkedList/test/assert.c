#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int testFailed = 0;
int testTotal = 0;

void assertEquals (int a, int b) {
	testTotal ++;
	if (a != b) {
		printf ("[Test n. %d] --> Mi aspettavo %d, ho ricevuto %d\n", testTotal, a, b);
		testFailed ++;
		return;
	}
}

void assertFloatEquals (float a, float b) {
	testTotal ++;
	if (a != b) {
		printf ("[Test n. %d] --> Mi aspettavo %f, ho ricevuto %f\n", testTotal, a, b);
		testFailed ++;
		return;
	}
}

void assertStrEquals (char *a, char *b) {
	testTotal ++;
	if (strcmp(a, b) != 0) {
		printf ("[Test n. %d] --> Mi aspettavo '%s', ho ricevuto '%s'\n", testTotal, a, b);
		testFailed ++;
		return;
	}
}

void assertNotNull (void* notNullable) {
	testTotal++;
	if (notNullable == NULL) {
		printf("[Test n. %d] --> Mi aspettavo un valore non nullo, ho ricevuto NULL\n", testTotal);
		testFailed++;
		return;
	}
}

void assertNull (void* nullable) {
	testTotal++;
	if (nullable != NULL) {
		printf("[Test n. %d] --> Mi aspettavo un valore nullo, ho ricevuto non null\n", testTotal);
		testFailed++;
		return;
	}
}

void print_test_results () {
	printf("Test Eseguiti: %d, Falliti: %d, Successo: %d\n", testTotal, testFailed, (testTotal - testFailed));
}