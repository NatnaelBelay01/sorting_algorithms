#include "sort.h"

/**
 * bubble_sort - a function that uses bubble sort to sort
 * @array: a pointer to the array
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 1, check = 0;
	int temp;

	while (1)
	{
		if (array[i] < array[i - 1])
		{
			temp = array[i];
			array[i] = array[i - 1];
			array[i - 1] = temp;
			print_array(array, size);
			check = 1;
			i++;
			continue;
		}
		i++;
		if (i >= size)
		{
			if (check == 0)
				break;
			i = 1;
			check = 0;
		}
	}
}
