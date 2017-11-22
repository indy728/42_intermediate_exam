/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:19:24 by kmurray           #+#    #+#             */
/*   Updated: 2017/10/09 22:09:59 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

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

char	*longest_subarray(char *arr);

void	print_example(int n, char *input, char *ans, char *output)
{
	printf("-------------------------------------------------------------------------\n\n");
	printf(BOLD"Example %d\nInput: "RESET"%s\n", n, input);
	printf(BOLD"Expected: "RESET""YELLOW"%s\n"RESET, ans);
	printf(BOLD"Output: "RESET"%s%s\n\n"RESET, strcmp(output, ans) ? RED : GREEN, output);
} 

int main()
{
	char *input;
	char *ans;
	char *output;

	input = "134";
	ans = "34";
	output = longest_subarray(input);
	print_example(1, input, ans, output);

	input = "454";
	ans = "45";
	output = longest_subarray(input);
	print_example(2, input, ans, output);

	input = "1357913579024680213579";
	ans = "79135790246802";
	output = longest_subarray(input);
	print_example(3, input, ans, output);

	input = "2010102";
	ans = "0101";
	output = longest_subarray(input);
	print_example(4, input, ans, output);

	input = "42424242424242";
	ans = "";
	output = longest_subarray(input);
	print_example(5, input, ans, output);
	
	return (0);
}
