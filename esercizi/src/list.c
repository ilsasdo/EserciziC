#ifndef __LIST_C_
#define __LIST_C_

#include "list.h"

list list_crea (void* value) {
	list l;
	l.index = 0;
	l.value = value;
	return l;
}

// Funzione list_add che aggiunga un elemento alla fine di una lista di interi e restituisca un puntatore a quella lista
// list* list_add (list *l, void* value) {

	// // Controllo che la lista in cui inserire l'elemento sia valida
	// if (l != NULL) {
	// 	if (l->next == NULL) {
	// 		if (!(l->next = (list *) calloc(1, sizeof(list)))) {
	// 			printf ("list_add: errore di allocazione memoria\n");
	// 			return NULL;
	// 		}
	//
	// 		l->next->index = ind;
	//
	// 		// Copio la stringa del nome
	// 		if (id) {
	// 			strcpy((l->next->name), id);
	// 		}
	//
	// 		// Inserimento avvenuto con Successo
	// 		return l;
	// 	} else {
	// 		// chiamata ricorsiva
	// 		list_add (l->next, ind, id);
	// 	}
	// }	else {
	// 	if (!(l = (list *) malloc(sizeof(list)))) {
	// 		printf ("list_add: Errore nell'allocazione di memoria\n");
	// 		return NULL;
	// 	}
	//
	// 	// Crea la nuova lista inserendo l'elemento desiderato
	// 	l->index = ind;
	//
	// 	// Copio la stringa del nome
	// 	if (id) {
	// 		strcpy((l->name),id);
	// 	}
	//
	// 	// Inserimento avvenuto con Successo
	// 	l->next = NULL;
	// 	return l;
	// }
//
// 	return l;
// }
/*
// Trova il primo elemento con indice == ind
list* list_find (list *l, int ind) {
	if (l) {
		if ((l -> index) == ind) {
			// Restituisco il puntatore all'elemento giusto
			return l;
		}

		// Chiamata Ricorsiva
		return (list_find ((l->next),ind));
	}

	 // Ricerca fallita miseramente, restituisco un null
	return l;
}

// Trova il primo elemento con name == id
list* list_namefind (list *l, const char* id)
{
	if (l && id)
		if ((strcmp (l->name, id)) == 0)
			return l; // Restituisco il puntatore all'elemento giusto
		else
			return list_namefind (l->next, id);	// Chiamata Ricorsiva
	else
		return l; // Ricerca fallita miseramente, restituisco un null
}

// Funzione che elimina un elemento di index "ind" dalla lista e libera la memoria allocata
list* list_del (list *l, int ind)
{
	list *next;

	if (l)
	{
		if( l->index == ind )
		{
			next = l->next;		// Se ha trovato l'indice giusto elimina ed aggiorna
			free (l);
			l = next;

			return l;	// successo, ho eliminato
		}

		next = l;

		while( next->next != NULL )
		{
			if( next->next->index == ind )
			{
				list *temp = next->next->next;
				free (next->next);
				next->next = temp;

				return l;	// successo, ho eliminato
			}
			else
				next = next->next;
		}
	}
	return l;	// non ho trovato nulla da eliminare
}

// Funzione che elimina un elemento dalla lista sapendone il nome e libera la memoria allocata
list* list_namedel (list *l, char* id)
{
	list *next;

	if ((l)&&(id))
	{
		if ((strcmp((l -> name),id))==0)		// Confronta le stringhe, verificare correttezza
		{
			next = l->next;		// Se ha trovato l'indice giusto elimina ed aggiorna
			free(l);
			l = next;

			return l;	// successo, ho eliminato
		}

		next = l;

		while(next->next != NULL)
		{
			if (strcmp(next->next->name,id)==0)		// Confronta le stringhe, verificare correttezza
			{
				list *temp = next->next->next;
				free(next->next);
				next->next = temp;

				return l;	// successo, ho eliminato
			}
			else
				next = next->next;
		}
	}
	return l;	// non ho trovato nulla da eliminare
}

// Funzione che cerca l'ennesimo elemento in lista e ne ritorna il puntatore
list* list_get (list *l, int n)
{
	if(l)
		if(n)
			return list_get(l->next, n-1);
		else
			return l;
	else
	{
		printf ("list_get: errore, indice troppo alto\n");
		return NULL;	// Error: out of bounds...
	}
}
*/
#endif
