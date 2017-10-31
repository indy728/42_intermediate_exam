#ifndef ALONG_H
# define ALONG_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_tree
{
	char			*str;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

int		g;

void	insert(t_tree **root, t_tree *new);
void	print_tree(t_tree *root);
void	destroy_tree(t_tree *root);
t_tree	*create_node(char *str, int i);

int		oa_strlen(char *str, int i);
char	*oa_strdup(char *str, int i);
void	ft_putstr(char *str);

int		get_value(char *root, char *new);

#endif
