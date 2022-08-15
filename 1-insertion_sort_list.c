#include "sort.h"

/**
 * insertion_sort_list - a function that sorts using insertion sort
 * @list: the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = *list, *back, *node, *n_node;

	if (*list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	n_node = node;
	while (sorted != NULL && node != NULL)
	{
		n_node = n_node->next;
		if (node->n >= sorted->n)
		{
			sorted = node;
			node = n_node;
			continue;
		}
		else
		{
			sorted->next = node->next;
			if (node->next)
				sorted->next->prev = sorted;
			node->next = sorted;
			node->prev = sorted->prev;
			if (sorted->prev)
				sorted->prev->next = node;
			sorted->prev = node;
			if (!node->prev)
				*list = node;
			print_list(*list);
			back = node->prev;
			while (back != NULL && back->n > node->n)
			{
				back->next = node->next;
				back->next->prev = back;
				node->next = back;
				node->prev = back->prev;
				if (back->prev)
					back->prev->next = node;
				back->prev = node;
				if (!node->prev)
					*list = node;
				print_list(*list);
				back = node->prev;
			}
		}
		node = n_node;
	}
}
