/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:11:13 by kmurray           #+#    #+#             */
/*   Updated: 2017/10/09 20:23:20 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int volume_histogram(int *histogram, int size);

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int size = ac - 1;
		int histogram[size];
		int	i = 0;

		while (++i < ac){
			histogram[i - 1] = atoi(av[i]);
		}
		printf("volume: %d\n", volume_histogram(histogram, size));
	}
	return (0);
}
