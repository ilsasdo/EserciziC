#include "linked_list.h"

/*
MergeSort(headRef)
1) If head is NULL or there is only one element in the Linked List
		then return.
2) Else divide the linked list into two halves.
FrontBackSplit(head, &a, &b); // a and b are two halves
3) Sort the two halves a and b.
MergeSort(a);
MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here)
and update the head pointer using headRef.
*headRef = SortedMerge(a, b);
*/

/* See https://www.geeksforgeeks.org/?p=3622 for details of this
   function */
linked_list* _sorted_merge(linked_list* a, linked_list* b, compare_function compare) {
	linked_list* result = NULL;

	/* Base cases */
	if (a == NULL) {
		return(b);
	}

	if (b == NULL) {
		return(a);
	}

	/* Pick either a or b, and recur */
	if (compare(a->value, b->value) <= 0) {
		result = a;
		result->next = _sorted_merge(a->next, b, compare);
	} else {
		result = b;
		result->next = _sorted_merge(a, b->next, compare);
	}
	return(result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.
     If the length is odd, the extra node should go in the front list.
     Uses the fast/slow pointer strategy.  */
void _front_back_split(linked_list* source,
					   linked_list** frontRef, linked_list** backRef) {
	linked_list* fast;
	linked_list* slow;
	if (source == NULL || source->next == NULL) {
		/* length < 2 cases */
		*frontRef = source;
		*backRef = NULL;
	} else {
		slow = source;
		fast = source->next;

		/* Advance 'fast' two nodes, and advance 'slow' one node */
		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				slow = slow->next;
				fast = fast->next;
			}
		}

		/* 'slow' is before the midpoint in the list, so split it in two
		  at that point. */
		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
}

/* sorts the linked list by changing next pointers (not data) */
void _merge_sort (linked_list** headRef, compare_function compare) {
	linked_list* head = *headRef;
	linked_list* a;
	linked_list* b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	_front_back_split(head, &a, &b);

	/* Recursively sort the sublists */
	_merge_sort(&a, compare);
	_merge_sort(&b, compare);

	/* answer = merge the two sorted lists together */
	*headRef = _sorted_merge(a, b, compare);
}

linked_list* linked_list_create (void* element) {
	linked_list* ll = (linked_list*) malloc(sizeof(linked_list));
	ll->value = element;
	ll->next = NULL;
	return ll;
}

linked_list* linked_list_add (linked_list* ll, void* element) {
	linked_list* last = linked_list_get_last(ll);
	linked_list* new_l = linked_list_create(element);
	last->next = new_l;
	return last->next;
}

linked_list* linked_list_filter (linked_list* ll, filter_function filter) {
	linked_list* filtered = NULL;
	linked_list* current = ll;

	while (current) {
		if (filter(current->value)) {
			if (filtered == NULL) {
				filtered = linked_list_create(current->value);
			} else {
				linked_list_add(filtered, current->value);
			}
		}

		current = current->next;
	}

	return filtered;
}

void linked_list_sort_asc (linked_list** list, compare_function compare) {
	_merge_sort(list, compare);
}

linked_list* _reverse(linked_list *list, linked_list *last) {
	if (list == NULL) {
		return last;
	}
	linked_list* next = list->next;
	list->next = last;
	return _reverse(next, list);
}

linked_list* linked_list_reverse (linked_list* list) {
	return _reverse(list, NULL);
}

void linked_list_sort_desc (linked_list** list, compare_function compare) {
	_merge_sort(list, compare);
	*list = linked_list_reverse(*list);
}

void* linked_list_get (linked_list* list, int index) {
	int size = 0;
	linked_list* last = list;
	do {
		if (size == index) {
			return last->value;
		}

		size ++;
		last = last->next;
	} while (last);

	return NULL;
}

linked_list* linked_list_get_last (linked_list* ll) {
	linked_list* last = ll;
	while (last->next) {
		last = last->next;
	}
	return last;
}

int linked_list_size (linked_list* ll) {
	int size = 0;
	linked_list* last = ll;
	while (last) {
		last = last->next;
		size ++;
	}

	return size;
}

linked_list* linked_list_map (linked_list* ll, map_function map) {
	linked_list* current = ll;
	linked_list* mapped = NULL;
	while (current) {
		void* el = map(current->value);

		if (mapped == NULL) {
			mapped = linked_list_create(el);
		} else {
			linked_list_add(mapped, el);
		}

		current = current->next;
	};

	return mapped;
}

void linked_list_reduce (linked_list* ll, void* init, reduce_function reduce) {
	linked_list* current = ll;
	while (current) {
		reduce(init, current->value);
		current = current->next;
	};
}
