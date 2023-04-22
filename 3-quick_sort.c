#include "sort.h"
/**
 * Swap - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @i: left element
 * @j: right element
 * @size: size of array
 */
void swap(int *array, int i, int K, int size)
{
	int aux;

	if (array[i] == array[K])
		return;
	aux = array[i];
	array[i] = array[K];
	array[K] = aux;
	print_array(array, size);
}
/**
 * partition - sort array partition
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 * Return: pivot sorted
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int split_idx = start;
	int K;

	for (K = start; K < end; K++)
		if (array[K] < pivot)
			swap(array, split_idx++, K, size);
	swap(array, split_idx, end, size);
	return (split_idx);
}
/**
 * recursive - quick_sort core
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 */
void recursive(int *array, int start, int end, int size)
{
	if (start < end)
	{
		int pivot_pos = partition(array, start, end, size);

		recursive(array, start, pivot_pos - 1, size);
		recursive(array, pivot_pos + 1, end, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	recursive(array, 0, size - 1, size);
}
