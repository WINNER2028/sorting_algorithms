#include "sort.h"
/**
 * selection_sort - it sorts an array of integers in ascending order
 * @array: the element to be sorted
 * @size: size of array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, k;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		unsigned int x = i;
		int aux = array[i];

		for (k = i + 1; k < size; k++)
		{
			if (array[k] < aux)
				aux = array[k], x = k;
		}
		if (x != i)
		{
			array[x] = array[i];
			array[i] = aux;
			print_array(array, size);
		}
	}
}
