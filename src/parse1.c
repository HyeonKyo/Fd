#include "fdf.h"

int		check_input(int ac, char **av)
{
	int	fd;

	if (ac < 1)
		error("Input error!");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error("Open error!");
	return (fd);
}

void	expand_arr(int ***arr, t_map_len *map)
{
	int	i;
	int	**tmp;

	tmp = (int **)malloc(sizeof(int *) * (map->y + 1));
	merror(tmp);
	i = -1;
	while (++i < map->y)
		tmp[i] = (*arr)[i];
	if (*arr)
		free(*arr);
	*arr = tmp;
}

void	fill_value(int **arr, char **buf, t_map_len *map)
{
	int	len_x;
	int	i;

	len_x = 0;
	while (buf[len_x])
		len_x++;
	map->x = len_x;
	arr[map->y] = (int *)malloc(sizeof(int) * len_x);
	merror(arr[map->y]);
	i = -1;
	while (buf[++i])
		arr[map->y][i] = ft_atoi(buf[i]);
}

int	**save_vector(int fd, t_map_len *map)
{
	char	*line;
	char	**buf;
	int		**arr;

	arr = 0;
	while (get_next_line(fd, &line) > 0)
	{
		buf = ft_split(line, ' ');
		expand_arr(&arr, map);
		fill_value(arr, buf, map);
		clear_str(buf, &line);
		map->y++;
	}
	return (arr);
}
