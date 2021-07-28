#include "fdf.h"

t_vector	*make_vector(int **arr, t_map_len *map)
{
	t_vector	*vec;
	int	len;
	int	i;
	int	idx_x;
	int	idx_y;

	len = map->x * map->y;
	vec = (t_vector *)malloc(sizeof(t_vector) * len);
	merror(vec);
	idx_y = -1;
	i = 0;
	while (++idx_y < map->y)
	{
		idx_x = -1;
		while (++idx_x < map->x)
		{
			vec[i].x = idx_x;
			vec[i].y = idx_y;
			vec[i++].z = arr[idx_y][idx_x];
		}
	}
	clear_arr(arr, map);
	return (vec);
}

t_map *parsing_map(int ac, char **av)
{
	int		fd;
	char	*line;
	int		**arr;
	t_map	*data;

	line = 0;
	data = create_data();
	fd = check_input(ac, av);
	arr = save_vector(fd, data->map);
	data->vec = make_vector(arr, data->map);
	data->size = data->map->x * data->map->y;
	return (data);
	//save vector
	//gnl로 한 줄씩 읽음
	//그 문자열 한줄을 split으로 잘라냄
	//그 문자열의 개수가 map_x길이가 됨
	//그 map_x만큼 int buf할당
	//int **arr[i]에 그 buf넣기
	//int **arr의 할당은 계속 1씩 늘려준다.
	//하지만 arr[i]의 주소값은 계속 남아있으므로 문제 없다.
	//정수 배열을 다 저장했으면, 그 정수 배열의 인덱스들이 x, y값이 되고 값이 z가 된다.
	//max_x * max_y만큼 벡터 구조체 배열 할당 후 차례로 넣어준다.
	//그 구조체 리턴
}
