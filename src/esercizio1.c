#include "esercizio1.h"

int isFineNomeProdotto (char *nome) {
  if ('"' == nome[strlen (nome)-1]) {
    return 1;
  } else {
    return 0;
  }
}

void getNomeProdotto (FILE *fp, char *nome) {
  char tmp[256];
  int read = 0;
  do {
    fscanf(fp, "%s", tmp);
    if (strlen(nome) > 0) {
      strcat(nome, " ");
    }
    strcat(nome, tmp);
    printf("%s\n", nome);
  } while (isFineNomeProdotto(tmp) == 0);
}

void esercizio1 (char *nomeFile) {
  FILE *fp = fopen (nomeFile, "r");
}
