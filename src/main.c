#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main () {
  //printf("fine nome prodotto? %d\n", isFineNomeProdotto("ciao\""));

  char nome[256];
  FILE *fp = fopen("data/dati.txt", "rt");
  if (fp == NULL) {
      printf("Errore nell'aprire il file: %d!\n", errno);
      return -1;
  }

  getNomeProdotto(fp, nome);

  fclose(fp);

  printf("nome prodotto: %s \n", nome);
}
