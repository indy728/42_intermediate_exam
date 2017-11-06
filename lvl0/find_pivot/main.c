#include <stdio.h>
#include <stdlib.h>
# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define BBLACK "\x1b[40m"
# define BRED "\x1b[41m"
# define BGREEN "\x1b[42m"
# define BYELLOW "\x1b[43m"
# define BBLUE "\x1b[44m"
# define BMAGENTA "\x1b[45m"
# define BCYAN "\x1b[46m"
# define BWHITE "\x1b[47m"
# define RESET "\x1b[0m"
# define CLEAR "\033c"
# define BOLD "\033[1m"

int	find_pivot(int *arr, int size);

int arr1[] =  { 1, 2, 3, 4, 0, 6 };
int arr2[] =  { -5, 10, 2, 5 };
int arr3[] =  { 1, -100, 0, 0, 1 };
int arr4[] =  { 7, 9, 8 };
int arr5[] =  { 1, 2 };
int	arr6[] =  { 2, 8, 4, 7, 0, -79, 69, 100, -69 };

void	print_array(int *arr, int size)
{
	int i = -1;

	printf(BOLD"Given array: [ ");
	while (++i < size - 1)
		printf("%d, ", arr[i]); 
	printf("%d ]\n"RESET, arr[i]); 
}

int main()
{
	int	fp;
	int	ans;

	print_array(arr1, 6);
	fp = find_pivot(arr1, 6);
	ans = 3;
	printf(YELLOW"Expected: "BOLD"%d\n"RESET, ans);
	printf("%sOutput: "BOLD"%d\n"RESET, fp == ans ? GREEN : RED, fp);
	print_array(arr2, 4);
	fp = find_pivot(arr2, 4);
	ans = 2;
	printf(YELLOW"Expected: "BOLD"%d\n"RESET, ans);
	printf("%sOutput: "BOLD"%d\n"RESET, fp == ans ? GREEN : RED, fp);
	print_array(arr3, 5);
	fp = find_pivot(arr3, 5);
	ans = 1;
	printf(YELLOW"Expected: "BOLD"%d\n"RESET, ans);
	printf("%sOutput: "BOLD"%d\n"RESET, fp == ans ? GREEN : RED, fp);
	print_array(arr4, 3);
	fp = find_pivot(arr4, 3);
	ans = -1;
	printf(YELLOW"Expected: "BOLD"%d\n"RESET, ans);
	printf("%sOutput: "BOLD"%d\n"RESET, fp == ans ? GREEN : RED, fp);
	print_array(arr5, 2);
	fp = find_pivot(arr5, 2);
	ans = -1;
	printf(YELLOW"Expected: "BOLD"%d\n"RESET, ans);
	printf("%sOutput: "BOLD"%d\n"RESET, fp == ans ? GREEN : RED, fp);
	print_array(arr6, 9);
	fp = find_pivot(arr6, 9);
	ans = 4;
	printf(YELLOW"Expected: "BOLD"%d\n"RESET, ans);
	printf("%sOutput: "BOLD"%d\n"RESET, fp == ans ? GREEN : RED, fp);
	return (0);
}
