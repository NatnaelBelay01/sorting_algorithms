#include "sort.h"

/**
 * smallest - a function that returns the index of the smallest int
 * @array: the array
 * @size: the size of the array
 * Return: the index of the int
 */

size_t smallest(int *array, size_t size)
{
	size_t i, idx;
	int smal;

	for (i = 0; i < size; i++)
	{
		if (i == 0 || array[i] < smal)
		{
			smal = array[i];
			idx = i;
		}
	}
	return (idx);
}

/**
 * selection_sort - a function that sorts
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, idx;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < size; i++)
	{
		idx = smallest(array + i, size - i) + i;
		if (idx == i)
			continue;
		temp = array[i];
		array[i] = array[idx];
		array[idx] = temp;
		print_array(array, size);
	}
}
