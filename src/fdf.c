#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	multiplied_pixel(t_data *data)
{
	int	mul_x;
	int	mul_y;
	int	mul_z;
	size_t	i;

	mul_x = IMG_X_SIZE / (data->map->x);
	mul_y = IMG_Y_SIZE / (data->map->y);
	mul_z = (mul_x + mul_y) / 2;
	i = 0;
	while (i < data->size)
	{
		data->vec[i].x *= mul_x;
		data->vec[i].y *= mul_y;
		data->vec[i++].z *= mul_z;
	}
}

void	based_x(t_vector start, t_vector end, t_delta *diff, t_img *img)
{
	double	p;
	int	x;
	int	y;
	int	inc_x;
	int	inc_y;

	x = (int)start.x;
	y = (int)start.y;
	inc_x = 1;
	if (start.x > end.x)
		inc_x = -1;
	inc_y = 1;
	if (start.y > end.y)
		inc_y = -1;
	p = 2 * (diff->y - diff->x);//p의 초기값
	if (diff->y == 0)
	{
		while (start.x <= end.x ? x <= end.x : x >= end.x)
		{
			my_mlx_pixel_put(img, x, y, GR);
			x += inc_x;
		}
		return ;
	}
	while (start.x <= end.x ? x <= end.x : x >= end.x)
	{
		my_mlx_pixel_put(img, x, y, GR);
		x += inc_x;
		if (p >= 0)
		{
			y += inc_y;
			p += 2 * (diff->y - diff->x);
		}
		else
			p += 2 * diff->y;
	}
}

void	based_y(t_vector start, t_vector end, t_delta *diff, t_img *img)
{
	double	p;
	t_crd	crd;
	t_crd	inc;

	crd.x = (int)start.x;
	crd.y = (int)start.y;
	inc.x = 1;
	if (start.x > end.x)
		inc.x = -1;
	inc.y = 1;
	if (start.y > end.y)
		inc.y = -1;
	p = 2 * (diff->x - diff->y);//p의 초기값
	printf("start.y, end.y, p : %f %f\n", start.y, end.y);
	if (diff->x == 0)
	{
		while (start.y <= end.y ? crd.y <= end.y : crd.y >= end.y)
		{
			crd.y += inc.y;
			my_mlx_pixel_put(img, crd.x, crd.y, GR);
		}
		return ;
	}
	while (start.y <= end.y ? crd.y <= end.y : crd.y >= end.y)
	{
		my_mlx_pixel_put(img, crd.x, crd.y, GR);
		crd.y += inc.y;
		if (p >= 0)
		{
			crd.x += inc.x;
			p += 2 * (diff->x - diff->y);
		}
		else
			p += 2 * diff->x;
	}
}

//맨처음 start점은 임의로 찍어주고 나머지 모든 점,선은 bresenham함수 반복으로 찍어줌.
//start에 vec[0]넣어주고 나머지는 반복문으로 넣어줌
void	bresenham(t_vector start, t_vector end, t_img *img)
{
	t_delta	diff;

	diff.x = end.x - start.x;
	diff.y = end.y - start.y;
	if (diff.x >= diff.y)
		based_x(start, end, &diff, img);
	else
		based_y(start, end, &diff, img);
}

void	print_pixel_in_vector(t_img *img, t_data *data)
{
	/*
	1. iso_data에 mul_x, mul_y를 곱해주기
	2. 2점씩 골라서 bresenham함수로 선 하나씩 그려주기
		1. dx, dy의 차이에 따른 함수 구분
		2. dx가 크다면 -> based_x
			1. inc_x = 1, inc_y = 1(start, end의 값에 따라 -1)
			2. p의 초기값 = 2dy - dx
			3. 초기 x, y = start의 x, y값
			--반복문 시작--
			4. 다음 x, y값은 x + 1, y값은 p에 따라 달라짐
				p >= 0이면 y + 1, p < 0이면 y그대로
			5. 다음 p값 구함
				p >= 0이면 p = p + 2dy -2dx
				p < 0이면 p = p + 2dy
	3. 2번 반복문 돌리기(vec[i] i++하면서)
		4. 만약 i = map->x - 1이면 아래쪽 선만 그리기
		5. 일반적으론 i+1과 i+map->x벡터와 이어주기
		6. i가 map->x * (map->y - 1)부터는 오른쪽과만 이어주기
	*/
	size_t i = 0;
	t_vector	*vec;
	t_map_len	*map;

	multiplied_pixel(data);
	vec = data->vec;
	map = data->map;
	while (i < data->size - 1)
	{
		if (i < map->x * (map->y - 1))
			bresenham(vec[i], vec[i + map->x], img);
		if (i % map->x != map->x - 1)
			bresenham(vec[i], vec[i + 1], img);
		i++;
	}
}

void	print_map(t_data *iso_data)
{
	void *mlx;
	void *mlx_win;
	t_img img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, MLX_X_SIZE, MLX_Y_SIZE, "Hello 42 Seoul");
	img.img = mlx_new_image(mlx, IMG_X_SIZE + 500, IMG_Y_SIZE + 500);//1400 1200은 디파인 상수로 변경하기
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	print_pixel_in_vector(&img, iso_data);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 150, 100);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_data	*origin_data;
	t_data	*iso_data;

	origin_data = parsing_map(ac, av);
	make_iso_vector(origin_data);
	print_map(origin_data);
	/*
	3. 화면 출력(print_iso)
		1. 일련의 과정 수행
		2. 반복문으로 iso벡터의 점들 z값 제외해서 찍어줌
		3. 출력.
	*/
	return (0);
}
