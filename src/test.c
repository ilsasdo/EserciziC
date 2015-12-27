#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "esercizio1.h"
#include "list.h"

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
    printf ("[Test n. %d] --> Mi aspettavo %s, ho ricevuto %s\n", testTotal, a, b);
    testFailed ++;
    return;
  }
}

void assertNotNull (void* notNullable) {
  testTotal ++;
  if (notNullable == NULL) {
    printf ("[Test n. %d] --> Mi aspettavo un valore non nullo, ho ricevuto NULL\n", testTotal);
    testFailed ++;
    return;
  }
}

int main () {
  assertEquals (1, isFineNomeProdotto("ciao\""));
  assertEquals (0, isFineNomeProdotto("ciao"));

  Articolo articolo;
  char nome[256];
  FILE *fp;
  fp = apriFile("data/dati.txt");
  assertNotNull(fp);
  getNomeProdotto(fp, articolo.nome);
  assertStrEquals ("\"APPLE TV\"", articolo.nome);

  getPrezzo(fp, &(articolo.prezzo));
  assertFloatEquals (170.99, articolo.prezzo);

  int testInt = 5;
  list l = list_crea((void*)&testInt);
  assertNotNull(&l);
  assertEquals(testInt, *((int*)(l.value)));

  Feature f = getFeature(fp);
  assertStrEquals("peso", f.nome);
  assertStrEquals("123g", f.valore);

  printf ("Test Eseguiti: %d, Falliti: %d, Successo: %d\n", testTotal, testFailed, (testTotal - testFailed));

  return testFailed;
}
