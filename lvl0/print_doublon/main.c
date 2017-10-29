void	print_doublon(int *a, int na, int *b, int nb);

int main()
{
		int	a[] = {1, 2, 10, 15};
		int b[] = {2, 20, 40, 70};
		int c[] = {-5, 2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
		int d[] = {2, 4, 5, 6, 7, 10, 40, 70};
		int	e[] = {100, 200, 300};
		int f[] = {1, 2, 3, 4};
		int g[] = {6, 5, 4, 3};
		int h[] = {1, 2, 3, 4};
		int i[] = {6, 5, 4, 3};
		int j[] = {20, 8, 5, 3};

		print_doublon(a, 4, b, 4);
		print_doublon(c, 11, d, 8);
		print_doublon(e, 3, f, 4);
		print_doublon(g, 4, h, 4);
		print_doublon(i, 4, j, 4);
		return (0);
}
