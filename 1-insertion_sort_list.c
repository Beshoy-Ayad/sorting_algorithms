#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;
	int key;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		key = current->n;
		prev = current->prev;
		next = current->next;

		while (prev != NULL && key < prev->n)
		{
			prev->next = next;
			if (next != NULL)
				next->prev = prev;
			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;
			next = current->next;
			prev = current->prev;
			print_list(*list);
		}
		current = next;
	}
}
