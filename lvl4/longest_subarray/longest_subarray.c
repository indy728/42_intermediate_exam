/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:19:20 by kmurray           #+#    #+#             */
/*   Updated: 2017/10/09 22:23:18 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	is_equal(char *str, int len)
{
	int odd = 0;
	int even = 0;
	int i = -1;

	while (++i < len)
	{
		if ((str[i] - '0') % 2)
			++odd;
		else
			++even;
	}
	return(odd == even ? 1 : 0);
}

char	*subarray(char *str, int len)
{
	char	*new = (char *)malloc(len + 1);
	int		i = -1;

	new[len] = 0;
	while (++i < len)
		new[i] = str[i];
	return (new);
}

char *longest_subarray(char *arr)
{
	int len = strlen(arr);
	int sub = len % 2 ? len - 1 : len;
	int i;
	
	while (sub > 1)
	{
		i = 0;
		while (sub + i <= len)
		{
			if (is_equal(arr + i, sub))
				return (subarray(arr + i, sub));
			++i;
		}
		sub -= 2;
	}
	return (subarray(NULL, 0));
}
