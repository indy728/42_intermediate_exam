#include "count_island.h"

int		ft_strlen(char *str)
{
	int	len = -1;

	while(str[++len])
		;
	return (len);
}

void	ft_strcpy(char *new, char *old)
{
	int i = -1;
	while (old[++i])
		new[i] = old[i];
}

void	ft_strjoin(char **str, char *buf)
{
	int	len = ft_strlen(*str);
	char *new = (char *)malloc(len + 2);
	new[len] = *buf;
	new[len + 1] = 0;
	free(*str);
	*str = new;
}

void	ft_putstr(char *str, int len)
{
	write(1, str, len);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		char	buf[1];
		char	*file = (char *)malloc(1);
		*file = 0;
		int fd = open(av[1], O_RDONLY);
		int len = 0;
		int lines = 0;
		int count = 0;
		int	i = -1;
		int	j;
		int k;

		while (read(fd, buf, 1) > 0)
		{
			ft_strjoin(&file, buf);
			if (buf[0] == '\n')
				++lines;
			++count;
		}
		close(fd);
/*		fd = open(av[1], O_RDONLY);
		char	*line;
		line = (char *)malloc(len + 1);
		while (read(fd, line, len + 1) > 0)
		{
			line[len] = 0;
			ft_putstr(line, len);
			write(1, "\n", 1);
		}
		close(fd);*/
		ft_putstr(file, ft_strlen(file));
		len = lines / count - 1;
		char **map = (char **)malloc(sizeof(char *) * (lines + 1));
		map[lines] = NULL;
		while (++i < lines)
		{
			j = -1;
			map[i] = (char *)malloc(len + 1);
			map[i][len] = 0;
			while (++j < len)
				map[i][j] = file[i * (len + 1) + j];
		}
		i = -1;
		while (map[++i])
			ft_putstr(map[i], ft_strlen(map[i]));
	}
	else
		write(1, "\n", 1);
	return (0);
}
