#ifndef LINKEDLIST_LIBRARY_H
#define LINKEDLIST_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FALSE, TRUE } boolean;

typedef struct _list_element {
	int index;
	void *value;
	struct _list_element* next;
} linked_list;

// ritorna TRUE se l'elemento corrisponde al filtro richiesto
typedef boolean (*filter_function) (void* el);

// ritorna 0 se i due elmenti sono uguali, < 0 se il primo è minore del secondo, > 0 se il primo è maggiore del secondo
typedef int (*compare_function) (void* el1, void* el2);

// trasforma un elemento di una lista in un altro elemento.
typedef void* (*map_function) (void* el);

// funzione di aggregazione sull'elemento della lista.
typedef void (*reduce_function) (void* value, void* el);

// crea una nuova linked list con un elemento
linked_list* linked_list_create (void* value);

// filtra gli elementi di una lista ritornando una nuova lista con i soli elementi selezionati
linked_list* linked_list_filter (linked_list* list, filter_function filter);

// ordina gli elementi della lista con un comparator a scelta
void linked_list_sort_asc (linked_list** list, compare_function compare);

// ordina in modo inverso gli elementi della lista con un comparator a scelta
void linked_list_sort_desc (linked_list** list, compare_function compare);

// conta il numero di elementi presenti in una lista
int linked_list_size (linked_list* list);

// ritorna l'ultimo elemento della lista
linked_list* linked_list_get_last (linked_list* list);

// aggiunge un nuovo elemento alla lista
linked_list* linked_list_add (linked_list* list, void* value);

// ottiene il valore contenuto nell'i-esimo elemento della lista
void* linked_list_get (linked_list* list, int index);

// trasforma una lista di elementi in un'altra lista di elementi
linked_list* linked_list_map (linked_list* list, map_function map);

// trasforma una lista di elementi in un valore scalare.
void linked_list_reduce (linked_list* list, void* init, reduce_function reduce);

// inverte l'ordine di una lista
linked_list* linked_list_reverse(linked_list* list);

#endif