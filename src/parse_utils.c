#include "fdf.h"

void	clear_arr(int **arr, t_map_len *map)
{
	int	i;

	i = 0;
	while (i < map->y)
		free(arr[i++]);
	free(arr);
}

void	clear_str(char **buf, char **line)
{
	int	i;

	i = 0;
	while (buf[i])
		free(buf[i++]);
	free(buf[i]);
	free(buf);
	free(*line);
	*line = 0;
}

t_data	*create_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	merror(data);
	ft_memset(data, 0, sizeof(t_data));
	data->map = (t_map_len *)malloc(sizeof(t_map_len));
	merror(data->map);
	ft_memset(data->map, 0, sizeof(t_map_len));
	return (data);
}
