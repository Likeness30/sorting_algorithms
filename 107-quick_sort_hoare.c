/* Rufus */
#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - This swaps two integers in an array
 * @a: The 1st integer to swap
 * @b: The 2nd integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Function that orders a subset of an array of
 * integers according to the hoare partition scheme
 * @array: The array of integers
 * @size: The size of the array
 * @left: Starting index of the subset to order
 * @right: Ending index of the subset to order
 * Return: Final partition index
 * Description: Uses the last element of the partition as the pivot
 * Prints the array after each swap of two elements
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, under;

	pivot = array[right];
	for (above = left - 1, under = right + 1; above < under;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			under--;
		} while (array[under] > pivot);

		if (above < under)
		{
			swap_ints(array + above, array + under);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implements the quicksort algorithm through recursion
 * @array: An array of integers to sort
 * @size: The size of the array
 * @left: Starting index of the array partition to order
 * @right: Ending index of the array partition to order
 *
 * Description: This uses the Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - This sorts an array of integers in
 * ascending order using the quicksort algorithm
 * @array: An array of integers
 * @size: The size of the array
 *
 * Description: This uses the Hoare partition scheme
 * Prints the array after each swap of two elements
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
