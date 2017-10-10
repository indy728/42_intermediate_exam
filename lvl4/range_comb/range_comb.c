/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:21:01 by kmurray           #+#    #+#             */
/*   Updated: 2017/10/09 17:29:55 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int	g = 0;

typedef struct		s_tree
{
	int				*arr;
	int				size;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

void	insert_node(t_tree **root, t_tree *new)
{
	if (!*root)
		*root = new;
	else
	{
		int i = -1;
		int value = 0;
		while (++i <= new->size && !value)
			value = (*root)->arr[i] - new->arr[i];
		insert_node((value > 0) ? &(*root)->left : &(*root)->right, new);
	}
}

void	destroy_tree(t_tree *root)
{
	if (root)
	{
		destroy_tree(root->left);
		destroy_tree(root->right);
		free(root);
	}
}

void	add_to_array(t_tree *root, int **rc)
{
	if (root)
	{
		add_to_array(root->left, rc);
		rc[g++] = root->arr;
		add_to_array(root->right, rc);
	}
}

void	swap(int *a, int l, int i)
{
	int tmp = a[l];

	a[l] = a[i];
	a[i] = tmp;
}

void	permute(int *a, int l, int r, t_tree **root)
{
	int i = l - 1;
	t_tree *new;
	if (l == r)
	{
		i = -1;
		new = (t_tree *)malloc(sizeof(t_tree));
		new->arr = (int *)malloc(sizeof(int) * (r + 1));
		new->arr = (int *)memcpy(new->arr, a, sizeof(int) * (r + 1));
		new->size = r;
		new->left = NULL;
		new->right = NULL;
		insert_node(root, new);
	}
	else
	{
		while (++i <= r)
		{
			swap(a, l, i);
			permute(a, l + 1, r, root);
			swap(a, l, i);
		}
	}
}

int	factorial(int n)
{
	if (n > 1)
		n *= factorial(n - 1);
	return (n);
}

int	**range_comb(int n)
{
	int err = 0;
	int	f = factorial(n);
	t_tree	*root = NULL;
	if (0 >= n || n >= 13)
	{
		err = 1;
		f = 1;
	}
	int **rc = (int **)malloc(sizeof(int *) * (f + 1));
	rc[f] = NULL;
	if (err)
	{
		rc[0] = (int *)malloc(sizeof(int));
		rc[0][0] = -1;
		return (rc);
	}
	int i = -1;
	int	dummy[n - 1];
	i = -1;
	while (++i < n)
		dummy[i] = i;
	permute(dummy, 0, n - 1, &root);
	add_to_array(root, rc);
	destroy_tree(root);
	return (rc);	
}
