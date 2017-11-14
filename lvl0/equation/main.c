#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void	equation(int n);

int main()
{
	printf(BOLD"Example 1: n = 42\n"GREEN);
	equation(42);
	printf("\n"RESET);

	printf(BOLD"Example 2: n = 111\n"GREEN);
	equation(111);
	printf("\n"RESET);

	printf(BOLD"Example 3: n = 0\n"GREEN);
	equation(0);
	printf("\n"RESET);
}
