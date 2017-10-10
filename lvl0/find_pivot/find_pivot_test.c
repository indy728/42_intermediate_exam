#include <stdio.h>

int	find_pivot(int *arr, int size);

int arr1[] =  { 1, 2, 3, 4, 0, 6 };
int arr2[] =  { -5, 10, 2, 5 };
int arr3[] =  { 1, 100, 0, 0, 1 };
int arr4[] =  { 7, 9, 8 };
int arr5[] =  { 0, 0 };

void	print_array(int *arr, int size)
{
	int i = -1;

	printf("array: [ ");
	while (++i < size - 1)
		printf("%d, ", arr[i]); 
	printf("%d ]\n", arr[i]); 
}

int main()
{
	print_array(arr1, 6);
	printf("pivot: arr[%d]\n\n", find_pivot(arr1, 6));
	print_array(arr2, 4);
	printf("pivot: arr[%d]\n\n", find_pivot(arr2, 4));
	print_array(arr3, 5);
	printf("pivot: arr[%d]\n\n", find_pivot(arr3, 5));
	print_array(arr4, 3);
	printf("pivot: arr[%d]\n\n", find_pivot(arr4, 3));
	print_array(arr5, 2);
	printf("pivot: arr[%d]\n\n", find_pivot(arr5, 2));
	return (0);
}
