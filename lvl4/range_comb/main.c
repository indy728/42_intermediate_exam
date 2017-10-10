/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:23:38 by kmurray           #+#    #+#             */
/*   Updated: 2017/10/09 17:27:43 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int **range_comb(int n);

void	print_rc(int **rc, int n)
{
	int i = -1;
	int j;
	while (rc[++i])
	{
		j = -1;
		printf("{");
		while (++j < n - 1)
			printf(" %d,", rc[i][j]);
		printf(" %d }\n", rc[i][j]);
	}
}

void	destroy_arr(int **rc)
{
	int i = -1;
	while (rc[++i])
		free(rc[i]);
	free(rc);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int n = atoi(av[1]);
		int **rc = range_comb(n);
		print_rc(rc, n);
		destroy_arr(rc);
	}
	return (0);
}
