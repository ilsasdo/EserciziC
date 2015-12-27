#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "esercizio1.h"

int testFailed = 0;
int testTotal = 0;

void assertEquals (int a, int b) {
  testTotal ++;
  if (a != b) {
    printf ("--> Mi aspettavo %d, ho ricevuto %d\n", a, b);
    testFailed ++;
    return;
  }
}

void assertStrEquals (char *a, char *b) {
  testTotal ++;
  if (strcmp(a, b) != 0) {
    printf ("--> Mi aspettavo %s, ho ricevuto %s\n", a, b);
    testFailed ++;
    return;
  }
}

int main () {
  assertEquals (1, isFineNomeProdotto("ciao\""));

  char nome[256];
  getNomeProdotto(fopen("data/dati.txt", "r"), nome);
  assertStrEquals ("\"APPLE TV\"", nome);

  printf ("Test Eseguiti: %d, Falliti: %d, Successo: %d\n", testTotal, testFailed, (testTotal - testFailed));

  return testFailed;
}
