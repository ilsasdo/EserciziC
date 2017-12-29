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

  char nome[256];
  FILE *fp;
  fp = apriFile("data/dati.txt");

  Articolo articolo = readArticolo(fp);
  assertStrEquals ("\"APPLE TV\"", articolo.nome);
  assertFloatEquals (170.99, articolo.prezzo);
  assertStrEquals("peso", articolo.features[0].nome);
  assertStrEquals("123g", articolo.features[0].valore);
  assertEquals(1, articolo.numeroFeature);

  Articolo art = readArticolo(fp);
  assertStrEquals ("\"APPLE TV 1\"", art.nome);
  assertFloatEquals (171.99, art.prezzo);
  assertStrEquals("peso", art.features[0].nome);
  assertStrEquals("124g", art.features[0].valore);
  assertStrEquals("altezza", art.features[1].nome);
  assertStrEquals("101cm", art.features[1].valore);
  assertStrEquals("larghezza", art.features[2].nome);
  assertStrEquals("151cm", art.features[2].valore);
  assertStrEquals("profondità", art.features[3].nome);
  assertStrEquals("4cm", art.features[3].valore);
  assertEquals(4, art.numeroFeature);


  // assertNotNull(fp);
  // getNomeProdotto(fp, articolo.nome);
  // assertStrEquals ("\"APPLE TV\"", articolo.nome);
  //
  // getPrezzo(fp, &(articolo.prezzo));
  // assertFloatEquals (170.99, articolo.prezzo);
  //
  // int testInt = 5;
  // list l = list_crea((void*)&testInt);
  // assertNotNull(&l);
  // assertEquals(testInt, *((int*)(l.value)));
  //
  // articolo.numeroFeature = getFeatures(fp, articolo.features);
  // assertStrEquals("peso", articolo.features[0].nome);
  // assertStrEquals("123g", articolo.features[0].valore);
  // assertEquals(1, articolo.numeroFeature);




  printf ("Test Eseguiti: %d, Falliti: %d, Successo: %d\n", testTotal, testFailed, (testTotal - testFailed));

  return testFailed;
}
