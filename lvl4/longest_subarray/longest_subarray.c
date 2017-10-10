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

int		is_odd(int c)
{
	return (c & 1);
}

int	ft_ctoi(char c)
{
	return (c - '0');
}

char	is_equal(char *str, int i, int len)
{
	int odd = 0;
	int even = 0;
	int j = -1;
	while (++j < len)
	{
		if (is_odd(ft_ctoi(str[i + j])))
			++odd;
		else
			++even;
	}
	return(odd == even ? 1 : 0);
}

char *longest_subarray(char *arr)
{
	int whole = strlen(arr);
	int len = whole;
	if (is_odd(len))
		--len;
	int i;
	int j = len - 1;
	int k = -1;
	char *str;
	
	while (len > 1)
	{
		i = -1;
		while (++i + len - 1 < whole)
		{
			if (is_equal(arr, i, len))
			{
				str = (char *)malloc(len + 1);
				str[len] = 0;
				while (++k < len)
					str[k] = arr[i + k];
				return (str);
			}
		}
		len -= 2;
	}
	str = (char *)malloc(1);
	str[0] = 0;
	return (str);

}
