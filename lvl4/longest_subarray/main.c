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

char	*longest_subarray(char *arr);

int main(int ac, char **av)
{
	if (ac > 1)
	{
		char *str = longest_subarray(av[1]);
		printf("output: %s\n", str);
		free(str);
	}
	return (0);
}
