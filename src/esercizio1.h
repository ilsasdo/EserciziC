#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
  char nome[129];
  char valore[129];
} Feature;

typedef struct {
  char nome[256];
  float prezzo;

  Feature feature[128];
  int numeroFeature;
} Articolo;

int isFineNomeProdotto (char *nome);

void getNomeProdotto (FILE *fp, char *nome);
void getPrezzo (FILE *fp, float *prezzo);

FILE* apriFile (char *path);

Feature getFeature (FILE *fp);
