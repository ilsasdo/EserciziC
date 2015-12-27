#ifndef __LIST_H_
#define __LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _list
{
	int index;
	void *value;
	struct _list* next;
} list;

list list_crea (void* value);

// funzioni per aggiungere/togliere elementi dalla lista:
/*
// inserisce l'elemento di index "ind" e name "id" in coda alla lista
list* list_add (list *l, void *value);

// cancella l'elemento uguale a di index "ind"
list* list_del (list *l, int ind);

// cancella l'elemento uguale a di name "id"
list* list_namedel (list *l, char *id);

// ritorna l'index dell'n-esimo elemento in lista
list* list_get (list *l, int n);

// trova il primo elemento con index == ind
list* list_find (list *l, int ind);

// trova il primo elemento con name corrispondente ad "id"
list* list_namefind (list *l, const char* id);
*/
#endif
