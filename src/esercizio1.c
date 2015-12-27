#include "esercizio1.h"

int isFineNomeProdotto (char *nome) {
  if ('"' == nome[strlen (nome)-1]) {
    return 1;
  } else {
    return 0;
  }
}

void getNomeProdotto (FILE *fp, char *nome) {
  printf ("getNomeProdotto: nome=%s\n", nome);
  char tmp[256];
  int read = 0;
  do {
    fscanf(fp, "%s", tmp);
    if (strlen(nome) > 0) {
      strcat(nome, " ");
    }
    strcat(nome, tmp);
  } while (isFineNomeProdotto(tmp) == 0);
}

void getPrezzo (FILE *fp, float *prezzo) {
  fscanf(fp, "%f", prezzo);
}

void esercizio1 (char *nomeFile) {
  FILE *fp = fopen (nomeFile, "r");
}

FILE* apriFile (char *path) {
  FILE *fp = fopen (path, "r");

  if (fp == NULL) {
    printf("Errore nell'apertura del file: %d \n", errno);
  }

  return fp;
}

Feature getFeature (FILE *fp) {
  Feature feature;
  fscanf(fp, "%s%s", feature.nome, feature.valore);
  return feature;
}

int getFeatures (FILE *fp, Feature features[]) {
  int i = 0;
  while (i < 128) {
    char acapo;
    fscanf(fp, "%c", &acapo);
    if (acapo == '\n') {
      return i;
    }

    Feature f = getFeature(fp);
    features[i] = f;
    i++;
  }

  // in teoria qui non ci arriva mai
  return i;
}

Articolo readArticolo (FILE *fp) {
  Articolo articolo;
  printf ("readArticolo: %s %d \n", articolo.nome, articolo);
  getNomeProdotto(fp, articolo.nome);
  getPrezzo(fp, &(articolo.prezzo));
  articolo.numeroFeature = getFeatures(fp, articolo.features);
  return articolo;
}
