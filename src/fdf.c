#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_pixel_in_vector(t_img *img, t_data *iso_data)
{
	size_t	i;
	t_vector	*vec;

	i = 0;
	vec = iso_data->vec;
	while (i < iso_data->size)
	{
		my_mlx_pixel_put(img, vec[i].x, vec[i].y, GR);
		i++;
	}
}

void	print_map(t_data *iso_data)
{
	void *mlx;
	void *mlx_win;
	t_img img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, iso_data->map->x + 200, iso_data->map->y + 200, "Hello 42 Seoul");
	img.img = mlx_new_image(mlx, iso_data->map->x, iso_data->map->y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	print_pixel_in_vector(&img, iso_data);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_data	*origin_data;
	t_data	*iso_data;

	origin_data = parsing_map(ac, av);
	iso_data = make_iso_vector(origin_data);
	print_map(iso_data);
	/*
	3. 화면 출력(print_iso)
		1. 일련의 과정 수행
		2. 반복문으로 iso벡터의 점들 z값 제외해서 찍어줌
		3. 출력.
	*/
	return (0);
}
