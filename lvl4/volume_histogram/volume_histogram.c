/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:03:34 by kmurray           #+#    #+#             */
/*   Updated: 2017/10/09 21:17:12 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int *arr, int size)
{
	int i = -1;
	int max = 0;

	while (++i < size)
		max = (arr[i] > max) ? arr[i] : max;
	return (max);
}

int	volume_histogram(int *histogram, int size)
{
	int n = ft_max(histogram, size);
	int		*arr = histogram;
	int	i;
	int j;
	int	k;
	int flag;
	int count = 0;

	i = -1;
	while (++i < n)
	{
		j = -1;
		flag = 0;
		k = size;
		while (++j < k)
		{
			if (flag == 1)
			{
				while (flag == 1 && --k > j)
					flag = (arr[k] > i) ? 2 : 1;
			}
			if (arr[j] > i)
				++flag;
			else if (flag > 1)
				++count;
		}
	}
	return (count);
}
